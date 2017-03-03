#define UWU_STKLEN 65536

typedef struct uwuplusplus_variable_s
{
	int type;
	void *value;
} variable_t; 

extern variable_t vstack[UWU_STKLEN];