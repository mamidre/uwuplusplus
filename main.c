#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "uwu.h"

void variable_t vstack[UWU_STKLEN];
int UWU_STKIDX = 0;

stmt_t uwu_init_stmt(size_t arglen) {
	stmt_t stmt = 0;
	memset(&stmt, 0, sizeof(stmt));
	stmt.instr = malloc(sizeof(char *));
	stmt.args = malloc(sizeof(char *) * arglen);
	for (int i = 0; i < arglen; i++) stmt.args[i] = malloc(sizeof(char *));
	stmt->len = 0;
	return stmt;
}

void uwu_pop_stmt(stmt_t *stmt) {
	free(stmt->instr);
	for (int i = 0; i < stmt->len; i++) free(stmt->args[i]);
	free(stmt->args);
	stmt->len = 0;
}

void uwu_incr_stmt_arglen(stmt_t *stmt) {
	stmt->args = realloc(stmt->args, sizeof(char *) * stmt->len + 1);
	stmt->len++;
}

stmt_t uwu_parse_stmt(char *str) {
	stmt_t stmt = uwu_init_stmt(1);
	char *instr = strtok(str, " ");
	strcpy(stmt.instr, instr);
	char *token = strtok(NULL, ",");
	int idx = 0;
	while (token != NULL) {
		strcpy(stmt.args[idx], token);
		uwu_incr_stmt_arglen(&stmt);
		token = strtok(NULL, ",");
		idx++;
	}
	return stmt;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s <file>\n", argv[0]);
		return 1;
	}
	return 0;
}
