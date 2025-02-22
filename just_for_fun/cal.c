#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_VARIABLES 100000
#define MAX_NAME_LEN 3200

typedef enum { INT, FLOAT, ERROR } ValueType;

typedef struct {
    ValueType type;
    union {
        int iVal;
        double fVal;
    } value;
} Value;

typedef struct {
    char name[MAX_NAME_LEN];
    Value value;
} Variable;

Variable variables[MAX_VARIABLES];
int variableCount = 0;
const char *expression;
int hasError = 0;

Value parseExpression();
Value parseTerm();
Value parseFactor();
Value parseNumber();
Value parseAssignment();
void setVariable(const char *name, Value value);
Value getVariable(const char *name);

void error() {
    if (!hasError) {
        printf("Error\n");
        hasError = 1;
    }
}

void skipWhitespace() {
    while (*expression == ' ' || *expression == '\t') {
        expression++;
    }
}

int findVariable(const char *name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void setVariable(const char *name, Value value) {
    int index = findVariable(name);
    if (index != -1) {
        variables[index].value = value;
    } else {
        if (variableCount >= MAX_VARIABLES) {
            error();
            return;
        }
        strncpy(variables[variableCount].name, name, MAX_NAME_LEN - 1);
        variables[variableCount].name[MAX_NAME_LEN - 1] = '\0';
        variables[variableCount].value = value;
        variableCount++;
    }
}

Value getVariable(const char *name) {
    int index = findVariable(name);
    if (index == -1) {
        error();
        return (Value){.type = ERROR};
    }
    return variables[index].value;
}

Value createIntValue(int iVal) {
    return (Value){.type = INT, .value.iVal = iVal};
}

Value createFloatValue(double fVal) {
    return (Value){.type = FLOAT, .value.fVal = fVal};
}

Value createErrorValue() {
    return (Value){.type = ERROR};
}

Value parseAssignment() {
    skipWhitespace();
    const char *start = expression;

    if (!isalpha(*expression) && *expression != '_') {
        error();
        return createErrorValue();
    }
    while (isalnum(*expression) || *expression == '_') {
        expression++;
    }
    const char *newPosi=expression;
     int hasDoubleEqual=0;
     while(newPosi!=NULL && *newPosi!='='){
        newPosi++;
        if(*newPosi=='=')hasDoubleEqual=1;
     }
     if(hasDoubleEqual==1){
        for(int i=0;i<(newPosi-expression);i++){
            if (isalpha(*(expression + i)) || *(expression + i) == '_') {} 
                else {
                    error();
                    return createErrorValue();
                }

        }
     }
    char name[MAX_NAME_LEN];
    int length = expression - start;
    if (length >= MAX_NAME_LEN) {
        error();
        return createErrorValue();
    }
    strncpy(name, start, length);
    name[length] = '\0';

    skipWhitespace();
    if (*expression == '=') {
        expression++;
        skipWhitespace();

        if (*expression == '=') {
            error();
            return createErrorValue();
        }

        Value value = parseExpression();
        if (value.type == ERROR) {
            return createErrorValue();
        }
        setVariable(name, value);
        return value;
    } else {
        return getVariable(name);
    }
}

Value parseExpression() {
    Value value = parseTerm();
    if (value.type == ERROR) {
        return createErrorValue();
    }
    while (1) {
        skipWhitespace();
        if (*expression == '+') {
            expression++;
            Value term = parseTerm();
            if (term.type == ERROR) {
                return createErrorValue();
            }
            if (value.type == INT && term.type == INT) {
                value.value.iVal += term.value.iVal;
            } else {
                if (value.type == INT) value = createFloatValue(value.value.iVal);
                if (term.type == INT) term = createFloatValue(term.value.iVal);
                value.value.fVal += term.value.fVal;
                value.type = FLOAT;
            }
        } else if (*expression == '-') {
            expression++;
            Value term = parseTerm();
            if (term.type == ERROR) {
                return createErrorValue();
            }
            if (value.type == INT && term.type == INT) {
                value.value.iVal -= term.value.iVal;
            } else {
                if (value.type == INT) value = createFloatValue(value.value.iVal);
                if (term.type == INT) term = createFloatValue(term.value.iVal);
                value.value.fVal -= term.value.fVal;
                value.type = FLOAT;
            }
        } else {
            break;
        }
    }
    return value;
}

Value parseTerm() {
    Value value = parseFactor();
    if (value.type == ERROR) {
        return createErrorValue();
    }
    while (1) {
        skipWhitespace();
        if (*expression == '*') {
            expression++;
            Value factor = parseFactor();
            if (factor.type == ERROR) {
                return createErrorValue();
            }
            if (value.type == INT && factor.type == INT) {
                value.value.iVal *= factor.value.iVal;
            } else {
                if (value.type == INT) value = createFloatValue(value.value.iVal);
                if (factor.type == INT) factor = createFloatValue(factor.value.iVal);
                value.value.fVal *= factor.value.fVal;
                value.type = FLOAT;
            }
        } else if (*expression == '/') {
            expression++;
            Value factor = parseFactor();
            if (factor.type == ERROR || 
                (factor.type == INT && factor.value.iVal == 0) || 
                (factor.type == FLOAT && fabs(factor.value.fVal) < 1e-6)) {
                error();
                return createErrorValue();
            }
            if (value.type == INT && factor.type == INT) {
                value.value.iVal /= factor.value.iVal;
            } else {
                if (value.type == INT) value = createFloatValue(value.value.iVal);
                if (factor.type == INT) factor = createFloatValue(factor.value.iVal);
                value.value.fVal /= factor.value.fVal;
                value.type = FLOAT;
            }
        } else {
            break;
        }
    }
    return value;
}

Value parseFactor() {
    skipWhitespace();
    if (*expression == '(') {
        expression++;
        Value value = parseExpression();
        if (value.type == ERROR) {
            return createErrorValue();
        }
        skipWhitespace();
        if (*expression == ')') {
            expression++;
        } else {
            error();
            return createErrorValue();
        }
        return value;
    } else if (*expression == '-') {
        expression++;
        Value factor = parseFactor();
        if (factor.type == INT) {
            factor.value.iVal = -factor.value.iVal;
        } else if (factor.type == FLOAT) {
            factor.value.fVal = -factor.value.fVal;
        }
        return factor;
    } else if (isalpha(*expression) || *expression == '_') {
        return parseAssignment();
    } else if (isdigit(*expression) || *expression == '.') {
        return parseNumber();
    } else {
        error();
        return createErrorValue();
    }
}

Value parseNumber() {
    skipWhitespace();
    const char *start = expression;
    int hasDecimalPoint = 0;  
    int hasLeadingZero = 0; 
    if(*expression=='.'){
         error();
        return createErrorValue();
    }

    if (*expression == '0') {
        hasLeadingZero = 1;
        expression++;
    }
    if (hasLeadingZero && *expression == '.') {
        hasDecimalPoint = 1;
        expression++;
    } else if (hasLeadingZero && isdigit(*expression)) {
        error();
        return createErrorValue();
    }
    while (isdigit(*expression) || *expression == '.') {
        if (*expression == '.') {
            if (hasDecimalPoint) {  
                error();
                return createErrorValue();
            }
            hasDecimalPoint = 1;
        }
        expression++;
    }
    if (start == expression || *(expression - 1) == '.' || (*start == '.' && start + 1 == expression)) {
        error();
        return createErrorValue();
    }

    char buffer[64];
    int length = expression - start;
    if (length >= sizeof(buffer)) {  
        error();
        return createErrorValue();
    }
    strncpy(buffer, start, length);
    buffer[length] = '\0';

    if (hasDecimalPoint) {
        return createFloatValue(strtod(buffer, NULL));
    } else {
        return createIntValue(atoi(buffer));
    }
}



int main() {
    char input[256];
    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        expression = input;
        hasError = 0;
        skipWhitespace();

        if (*expression == '\0' || *expression == '\n') {
            continue;
        }

        Value result = parseExpression();

        skipWhitespace();
        if (*expression != '\0' && *expression != '\n') {
            error();
            continue;
        }

        if (result.type == ERROR || hasError) {
            continue;
        }

        if (result.type == INT) {
            printf("%d\n", result.value.iVal);
        } else if (result.type == FLOAT) {
            printf("%.6f\n", result.value.fVal);
        }
    }
    return 0;
}
