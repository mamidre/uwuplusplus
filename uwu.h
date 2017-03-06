#define UWU_STKLEN 65536

typedef struct uwuplusplus_variable_s {
	int type;
	void *value;
} variable_t; 

typedef struct uwuplusplus_stmt_s {
	char *instr;
	char **args;
} stmt_t;

extern variable_t vstack[UWU_STKLEN];
