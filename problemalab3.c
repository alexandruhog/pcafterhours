#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	char string[20];

	//vector de cuvinte in care salvam inputul
	char **input_save;
	//vector de cuvinte in care salvam cuvintele doar o data (chiar daca apar de mai multe ori)
	char **apparitions_save;
	//numarul de aparitii ale fiecarui element din apparitions_save
	int *apparitions_count;

	int number_of_different_strings = 0, cap = 3;
	int found;

	/**
	 * citesc n, aloc vectorul in care citesc cu dimensiunea n, iar vectorii
	 * in care salvez aparitiile distincte le initializez cu dimensiunea cap
	 */
	scanf("%d", &n);
	input_save = (char **)calloc(n, sizeof(char *));
	apparitions_save = (char **)calloc(cap, sizeof(char *));
	apparitions_count = (int *)calloc(cap, sizeof(int));

	/**
	 * citesc fiecare cuvant intr-un string alocat pe stiva
	 * il salvez in input_save dupa ce i-am alocat exact cata memorie am nevoie
	 */
	for (int i = 0; i < n; i++)
	{
		scanf("%s", string);
		input_save[i] = (char *)calloc(strlen(string) + 1, sizeof(char));
		strcpy(input_save[i], string);
	}

	/**
	 * pornesc o iteratie cu care trec prin fiecare element din vectorul de
	 * cuvinte in care am salvat inputul, si pentru fiecare element (i), compar
	 * stringul (input_save[i]), cu fiecare element (j) din vectorul de cuvinte
	 * distincte (apparitions_save[j]).
	 * 
	 * Daca cuvantul deja exista, nu il mai salvez, ci doar cresc numarul de
	 * aparitii corespondent acelui string (apparitions_count[j]), altfel,
	 * incerc sa il introduc (intrucat nu exista deja, inseamna ca va fi unic in
	 * acel vector).
	 */
	for (int i = 0; i < n; i++)
	{
		found = 0;
		for (int j = 0; j < number_of_different_strings; j++)
		{
			if (strcmp(input_save[i], apparitions_save[j]) == 0)
			{
				apparitions_count[j]++;
				found = 1;
				break;
			}
		}

		if (!found)
		{
			//daca as depasi capacitatea maxima, o cresc
			if (number_of_different_strings >= cap)
			{
				cap += 3;
				apparitions_save = (char **)realloc(apparitions_save, cap * sizeof(char *));
				apparitions_count = (int *)realloc(apparitions_count, cap * sizeof(int));
			}

			//aloc exact cat spatiu am nevoie in apparitions_save si copiez stringul
			apparitions_save[number_of_different_strings] = calloc(strlen(input_save[i]) + 1, sizeof(char));
			apparitions_count[number_of_different_strings] = 1;
			strcpy(apparitions_save[number_of_different_strings], input_save[i]);

			number_of_different_strings++;
		}
	}

	//printez elementele celor doi vectori si eliberez memoria (intrucat nu o mai folosesc)
	for (int i = 0; i < number_of_different_strings; i++)
	{
		printf("%s %d\n", apparitions_save[i], apparitions_count[i]);
		free(apparitions_save[i]);
	}

	free(apparitions_save);
	free(apparitions_count);
}