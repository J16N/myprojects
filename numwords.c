/* The MIT License (MIT)
 *
 * Copyright (c) 2021-present Mr. Rabbit
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct record 
{
    int value;
    int count;
    struct record *next;
} NODE;

void append(int data);
void display();
NODE *start = NULL;

char *tens[] = {
    [2] = "Twenty", [3] = "Thirty", [4] = "Forty",
    [5] = "Fifty", [6] = "Sixty", [7] = "Seventy",
    [8] = "Eighty", [9] = "Ninety"
};

char *ones_and_teens[] = {
    [0] = "Zero", [1] = "One", [2] = "Two", [3] = "Three",
    [4] = "Four", [5] = "Five", [6] = "Six", [7] = "Seven",
    [8] = "Eight", [9] = "Nine", [10] = "Ten", [11] = "Eleven",
    [12] = "Twelve", [13] = "Thirteen", [14] = "Fourteen", [15] = "Fifteen",
    [16] = "Sixteen", [17] = "Seventeen", [18] = "Eighteen", [19] = "Nineteen"
};

void num_to_words(int num) {
    if (num < 0)
        printf("Minus ");
        
    num = fabs(num);
    int length = num > 0 ? log10(num) : 0;
        
    switch (length) {
        case 0:
        case 1:
            if (num < 20) {
                printf("%s ", ones_and_teens[num]);
                num = 0;
            } 
            else {
                int place = pow(10, 1);
                printf("%s ", tens[num / place]);
                num %= place;
            }
            break;

        case 2:
        {
            int place = pow(10, 2);
            printf("%s Hundred ", ones_and_teens[num / place]);
            num %= place;
            break;
        }

        case 3:
        case 4:
        {
            int place = pow(10, 3);
            num_to_words(num / place);
            printf("Thousand ");
            num %= place;
            break;
        }

        case 5:
        case 6:
        case 7: 
        {
            int place = pow(10, 5);
            num_to_words(num / place);
            printf("Lakh ");
            num %= place;
            break;
        }

        default:
            printf("This number is too big!");
            num = 0;
    }

    if (num) num_to_words(num);
}

int main(int argc, char *argv[]) {
    int num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    append(num);
    display();
    printf("\n");

    return EXIT_SUCCESS;
}

void append(int data) {
    NODE *temp, *curr;
    temp = (NODE*) malloc(sizeof(NODE));
    int length = fabs(data) > 0 ? log10(fabs(data)) : 0;

    switch (length) {
        case 0:
        case 1:
        case 2:
        {
            temp -> value = data;
            data = -1;
            break;
        }

        case 3:
        case 4:
        {
            int place = pow(10, 3);
            temp -> value = data / place;
            data = abs(data) % place;
            break;
        }

        default:
        {
            int place = pow(10, 5);
            temp -> value = data / place;
            data = abs(data) % place;
        }
    }

    temp -> count = 1;
    temp -> next = NULL;
        
    if (start) {
        curr = start;
        ++(curr -> count);
        while (curr -> next) {
            curr = curr -> next;
            ++(curr -> count);
        }
        curr -> next = temp;
    }
    else start = temp;
        
    if (data >= 0) append(data);
}

void display() {
    NODE *curr = start;
    int iter = 0;
    
    while (curr) {
        int value = curr -> value;
        
        switch (curr -> count) {
            case 1:
                if (value > 0 || !iter) num_to_words(value);
                break;
                
            case 2:
                num_to_words(value);
                printf("Thousand ");
                break;
                
            case 3:
                num_to_words(value);
                printf("Lakh ");
                break;
        }
        ++iter;
        curr = curr -> next;
    }
}