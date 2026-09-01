int calPoints(char** operations, int operationsSize) {
    
    int stack[1000];
    int top = -1;

    for(int i = 0; i < operationsSize; i++){
        if(*operations[i] == 'C'){
            top--;
        }
        else if(*operations[i] == 'D'){
            top++;
            stack[top] = stack[top-1] * 2;
        }
        else if(*operations[i] == '+'){
            top++;
            stack[top] = stack[top-1] + stack[top-2];
        }
        else{
            top++;
            char num = *operations[i];
            int number = atoi(operations[i]);
            stack[top] = number;
        }
    }

    int totalScore = 0;
    while(top != -1){
        totalScore += stack[top];
        top--;
    }
    return totalScore;
}