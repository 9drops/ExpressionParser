#include "exp_parser.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int ret = 0;
	TYPE res_type = -1;
	FILE *fp = fopen("exp.test", "r");
	if (NULL == fp)
	{
		printf("open exp.test falied!\n");
		printf("if exp.test not exist, please create it, then fill one expression in one line.\n");
		return 0;
	}
	
	char exp[128] = {0};
	char result[1024]= {0};
	int exp_size = sizeof(exp);
	int res_size = sizeof(result);
	
	while (fgets(exp, sizeof(exp), fp))
	{
		*(exp + strlen(exp) - 1) = '\0';
		printf("exp:%s\n", exp);
		ret = exp_parser(exp, result, &res_type, res_size);
		printf("ret:%d, result:'%s' type:%d stype:%s\n\n", ret, result, res_type, exp_get_stype(res_type));
		memset(exp, 0, exp_size);
		memset(result, 0, res_size);
	}

	fclose(fp);
	return 0;
}
