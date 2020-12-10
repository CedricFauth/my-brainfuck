#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if (argc != 2) return 0;
	char *c = argv[1];
	FILE* out = fopen("bfout.c", "w");
	fputs("#include <stdio.h>\nint main(void){\n",out);
	fputs("int data[1000] = {0};\nint *ptr = data;\n",out);
	while (*c) {
		switch (*c) {
			case '+': fputs("++*ptr;",out); break;
			case '-': fputs("--*ptr;",out); break;
			case '>': fputs("++ptr;",out); break;
			case '<': fputs("--ptr;",out); break;
			case '.': fputs("\nputchar(*ptr);",out); break;
			case ',': fputs("\n*ptr=getchar();",out); break;
			case '[': fputs("\nwhile(*ptr){",out); break;
			case ']': fputs("\n}",out); break;
		}
		++c;
	}
	fputs("}\n", out);
	fclose(out);
	execlp("gcc", "gcc", "bfout.c", "-o", "bfout", (char *)NULL);
}

