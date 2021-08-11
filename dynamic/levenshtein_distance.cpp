#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//=====================================================================================================

const int INS_COST = 1;
const int DEL_COST = 1;
const int SUBST_COST = 1;

struct string{
	char *text;
	int size;
};

//=====================================================================================================

int get_levenshtein_distance(struct string *str1, struct string *str2);

int min(int a, int b, int c);

int min(int a, int b);

int diff(char a, char b);

int inscost();

int delcost();

int substcost(char a, char b);

//=====================================================================================================

int main()
{
	struct string str1 = {};
	struct string str2 = {};

	str1.text = (char *)calloc(102, sizeof(char));
	str2.text = (char *)calloc(102, sizeof(char));

	fgets(str1.text, 102, stdin);
	str1.size = strlen(str1.text) - 1;

	fgets(str2.text, 102, stdin);
	str2.size = strlen(str2.text) - 1;

	printf("%d\n", get_levenshtein_distance(&str1, &str2));

	free(str1.text);
	free(str2.text);

	return 0;
}

//=====================================================================================================

int get_levenshtein_distance(struct string *str1, struct string *str2)
{
	int min_size = min(str1->size, str2->size);
	int max_size = str1->size + str2->size - min_size;
	int tmp1 = 0, tmp2 = 0;
	int *dyn = (int *)calloc(min_size + 1, sizeof(int));
	char *small = (str1->size >= str2->size) ? str2->text : str1->text;
	char *big = (str1->size < str2->size) ? str2->text : str1->text;

	for(int i = 0; i <= min_size; i++)
	{
		dyn[i] = i;
	}

	for(int i = 1; i <= max_size; i++)
	{
		dyn[0] = i;
		tmp1 = i - 1;
		
		for(int j = 1; j <= min_size; j++)
		{
			tmp2 = dyn[j];
			dyn[j] = min(tmp2 + 1, dyn[j - 1] + 1, tmp1 + substcost(big[i - 1], small[j - 1]));
			tmp1 = tmp2;
		}
		
	}

	int answer = dyn[min_size];

	free(dyn);

	return answer;
}

//-----------------------------------------------------------------------------------------------------

int min(int a, int b, int c)
{
	return (((a > b) ? b : a) >= c) ? c : ((a > b) ? b : a);
}

//-----------------------------------------------------------------------------------------------------

int min(int a, int b)
{
	return (a > b) ? b : a;
}

//-----------------------------------------------------------------------------------------------------

int diff(char a, char b)
{
	return (a != b) ? 1 : 0;
}

//-----------------------------------------------------------------------------------------------------

int inscost()
{
	return INS_COST;
}

//-----------------------------------------------------------------------------------------------------

int delcost()
{
	return DEL_COST;
}

//-----------------------------------------------------------------------------------------------------

int substcost(char a, char b)
{
	return SUBST_COST * diff(a, b);
}
