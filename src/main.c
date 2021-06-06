#include <stdio.h>

#define MEM_SIZE 1000

#define PRINT_CMD(c, s) case c:                 \
    printf(s);                                  \
    break;

void print_header(void) {
    printf("#include <stdio.h>\n#include <string.h>\nint main() {\n");
    printf("int p = 0;\nchar a[%d];\n", MEM_SIZE);
    // initialize everything with 0
    printf("memset(a, 0, %d);\n", MEM_SIZE);
}

void print_footer(void) {
    printf("}");
}

int get_reps_helper(char wished, char neg, char* next) {
    int reps = 0;
    while ((*next = getchar()) == wished || *next == neg)
        if (*next == neg)
            reps--;
        else
            reps++;

    return reps;
}

int get_reps(char wished, char *next) {
    switch (wished) {
        case '+':
            return get_reps_helper(wished, '-', next);
        case '-':
            return get_reps_helper(wished, '+', next);
        case '>':
            return get_reps_helper(wished, '<', next);
        case '<':
            return get_reps_helper(wished, '>', next);
    }

	return -1;
}

char interpret_reped(char begin) {
    char result;
    // add one
    int reps = get_reps(begin, &result) + 1;

    switch (begin) {
        case '+':
        case '-':
            printf("a[p] %c= %d;\n", begin, reps);
            break;

        case '>':
        case '<':
            printf("p = (p %c %d) %% %d;\n",
                   begin == '>' ? '+' : '-',
                   reps,
		   MEM_SIZE
            );
    }

    return result;
}

char interpret(char c) {
    switch (c) {
        PRINT_CMD('.', "putchar(a[p]);\n")
        PRINT_CMD(',', "a[p] = getchar();\n")
        // makes a while loop for []
        PRINT_CMD('[', "while (a[p]) {\n")
        PRINT_CMD(']', "}\n")

		case '+':
		case '-':
		case '>':
		case '<':
			return interpret_reped(c);
        default:
            break;
    }

    return getchar();
}

int main(int argc, char** argv) {
    print_header();
    char next = getchar();

    while (next != EOF) {
        next = interpret(next);
    }

	print_footer();

	return 0;
}
