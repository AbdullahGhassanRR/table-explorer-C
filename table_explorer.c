/*
1. readFile() = function to read file
2. linearSearchStr() = function to search data
3. mergeAsc() = function to merge data ascendance order
4. mergeDsc() = function to merge data descendance order
5. mergeSort() = recursive function that sorting with merge sort method
6. exportData() = function to export a file
7. printData() = function to print raw data or sorted data

*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define x 3940
typedef struct table{
	// change these member below according to your table column name 
	char loc[100];
	char city[100];
	long rprice;
	char price[9], room[9], bath[11], car[9]; 
	char type[25];
	char furnish[25];
	
} dat;

dat data[x];
dat dataraw[x];
dat column;

int total = 0;
FILE *fp;

// READ FILE FUNCTION

int readFile()
{
	fp = fopen("file.csv", "r");
	if(fp == NULL)
	{
		printf("file not found\n");
		return 0;
	}
	
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", column.loc, column.city, column.price, column.room, column.bath, column.car, column.type, column.furnish);
	
	while(!feof(fp))
	{
		fscanf(fp, "%[^,],%[^,],%ld,%[^,],%[^,],%[^,],%[^,],%[^\n]\n", data[total].loc, data[total].city, &data[total].rprice, data[total].room, data[total].bath, data[total].car, data[total].type, data[total].furnish);
		total++; 
	}
	fclose(fp);
	return 1;
}

// SEARCH FUNCTION

void linearSearchStr(int kolom)
{
	int i, flag = 0; 
	char find[101];
	
if(kolom != 3)
{
		printf("What do you want to find? (Case-sensitive): \n");
	
		scanf(" %[^\n]", find);
		getchar();
	
	
	puts("");
	printf("%-26s%-19s%-16s%-10s%-15s%-11s%-12s%-10s\n", column.loc, column.city, column.price, column.room, column.bath, column.car, column.type, column.furnish);
	for(i = 0; i < total; i++)
	{
		if(kolom == 1 && strcmp(data[i].loc, find) == 0)
		{
			printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
			flag++;
			if(flag >= 10) break;
		}
		else if(kolom == 2 && strcmp(data[i].city, find)==0)	
		{
			printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
			flag++;
			if(flag >= 10) break;
		}
		else if(kolom == 4 && strcmp(data[i].room, find) == 0)
		{
			printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
			flag++;
			if(flag >= 10) break;
		}
		else if(kolom == 5 && strcmp(data[i].bath, find) == 0)
		{
			printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
			flag++;
			if(flag >= 10) break;
		}
		else if(kolom == 6 && strcmp(data[i].car, find) == 0)
		{
			printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
			flag++;
			if(flag >= 10) break;
		}
		else if(kolom == 7 && strcmp(data[i].type, find) == 0)
		{
			printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
			flag++;
			if(flag >= 10) break;
		}
		else if(kolom == 8 && strcmp(data[i].furnish, find) == 0)
		{
			printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
			flag++;
			if(flag >= 10) break;
		}
	}
}

if(kolom == 3)
{
	long angka;
	printf("What do you want to find? \n");
	scanf("%ld", &angka);
	puts("");
	
	printf("%-26s%-19s%-16s%-10s%-15s%-11s%-12s%-10s\n", column.loc, column.city, column.price, column.room, column.bath, column.car, column.type, column.furnish);
	for(i = 0; i < total; i++)
	{
			if(data[i].rprice == angka)
			{
			printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
			flag++;
			if(flag >= 10) break;
			}
		}
	}

	if (flag == 0)
	{
		printf("Data not found\n");
	}
	return;
}

// ALL SORT FUNCTION

void mergeAsc(dat data[], dat leftData[], dat rightData[], int left, int right, int* kolom3)
{
    int l = 0, r = 0, i = 0;

    while (l < left && r < right)
    {
        int compareResult;
        switch (*kolom3)
        {
        case 1:
            compareResult = strcmp(leftData[l].loc, rightData[r].loc);
            break;
        case 2:
            compareResult = strcmp(leftData[l].city, rightData[r].city);
            break;
        case 3:
            if(leftData[l].rprice < rightData[r].rprice)
            {
            	compareResult = -1;
			}
            break;
        case 4:
            compareResult = strcmp(leftData[l].room, rightData[r].room);
            break;
        case 5:
            compareResult = strcmp(leftData[l].bath, rightData[r].bath);
            break;
        case 6:
            compareResult = strcmp(leftData[l].car, rightData[r].car);
            break;
        case 7:
            compareResult = strcmp(leftData[l].type, rightData[r].type);
            break;
        case 8:
            compareResult = strcmp(leftData[l].furnish, rightData[r].furnish);
            break;
        default:
            printf("Invalid column number: %d\n", *kolom3);
            return;
        }

        if (compareResult < 0)
        {
            data[i] = leftData[l];
            ++l;
        }
        else
        {
            data[i] = rightData[r];
            ++r;
        }
        i++;
    }

    while (r < right)
    {
        data[i] = rightData[r];
        ++i;
        ++r;
    }

    while (l < left)
    {
        data[i] = leftData[l];
        ++i;
        ++l;
    }
}

void mergeDsc(dat data[], dat leftData[], dat rightData[], int left, int right, int* kolom3)
{
    int l = 0, r = 0, i = 0;

    while (l < left && r < right)
    {
        int compareResult;
        switch (*kolom3)
        {
        case 1:
            compareResult = strcmp(leftData[l].loc, rightData[r].loc);
            break;
        case 2:
            compareResult = strcmp(leftData[l].city, rightData[r].city);
            break;
        case 3:
            if(leftData[l].rprice > rightData[r].rprice)
            {
            	compareResult = 1;
			}
            break;
        case 4:
            compareResult = strcmp(leftData[l].room, rightData[r].room);
            break;
        case 5:
            compareResult = strcmp(leftData[l].bath, rightData[r].bath);
            break;
        case 6:
            compareResult = strcmp(leftData[l].car, rightData[r].car);
            break;
        case 7:
            compareResult = strcmp(leftData[l].type, rightData[r].type);
            break;
        case 8:
            compareResult = strcmp(leftData[l].furnish, rightData[r].furnish);
            break;
        default:
            printf("Invalid column number: %d\n", *kolom3);
            return;
        }

        if (compareResult > 0)
        {
            data[i] = leftData[l];
            ++l;
        }
        else
        {
            data[i] = rightData[r];
            ++r;
        }
        i++;
    }

    while (r < right)
    {
        data[i] = rightData[r];
        ++i;
        ++r;
    }

    while (l < left)
    {
        data[i] = leftData[l];
        ++i;
        ++l;
    }
}

void mergeSort(dat data[], int len, int* kolom3, int* deci)
{
    if (len <= 1)
        return;

    int left = len / 2;
    int right = len - left;

    dat *leftData = (dat *)malloc(left * sizeof(dat));
    dat *rightData = (dat *)malloc(right * sizeof(dat));

    int i;

for (i = 0; i < len; i++)
{
	if(i < left)
	{
		leftData[i] = data[i];
	}
	else
	{
		rightData[i-left] = data[i];
	}
}


    mergeSort(leftData, left, kolom3, deci);
    mergeSort(rightData, right, kolom3, deci);
	
	if(*deci == 1)
	{
    	mergeAsc(data, leftData, rightData, left, right, kolom3);
	}
	else if(*deci == 2)
	{
		mergeDsc(data, leftData, rightData, left, right, kolom3);
	}
	else
	{
		free(leftData);
		free(rightData);
	 } 
	
    free(leftData);
    free(rightData);
}

// EXPORT FUNCTION

void exportData()
{
	FILE *fp;
	int i;
	char fileBaru[101];
	printf("Type the name of new file (no space allowed): \n");
	scanf("%s", fileBaru); getchar();
	
	strncat(fileBaru, ".csv", sizeof(fileBaru) - strlen(fileBaru) - 1);
	
	fp = fopen(fileBaru, "w+");
	fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", column.loc, column.city, column.price, column.room, column.bath, column.car, column.type, column.furnish);
	for(i = 0; i < total; i++)
	{
		fprintf(fp, "%s,%s,%ld,%s,%s,%s,%s,%s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
	}
	
	printf("Data successfully written to file %s!\n", fileBaru);
	
	return;
}

// PRINT FUNCTION

void printData(int n)
{
	int i;
	puts("");
	printf("%-26s%-19s%-16s%-10s%-15s%-11s%-12s%-10s\n", column.loc, column.city, column.price, column.room, column.bath, column.car, column.type, column.furnish);
	
	if (n < x)
    {
        for (i = 0; i < n; i++)
        {
            printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
        }
        
    }
    else 
    {
    	for (i = 0; i < total; i++)
        {
            printf("%-26s%-19s%-16ld%-10s%-15s%-11s%-12s%-10s\n", data[i].loc, data[i].city, data[i].rprice, data[i].room, data[i].bath, data[i].car, data[i].type, data[i].furnish);
        }
	}

}

// MAIN

int main()
{
	int init;
	init = readFile();
	
	if(init != 1){
		return 0;
	};
	
	int select;
	do
	{
		printf("What do you want to do?\n");
		printf("1. Display data\n2. Search Data\n3. Sort Data\n4. Export Data\n5. Exit\n");
		printf("Your choice: ");
		scanf("%d", &select);
		
		if(select == 1)
		{
			system("cls");
			int row;
			printf("Number of rows: ");
			scanf("%d", &row);
			printData(row);
		}
		else if(select == 2)
		{
			system("cls");
			int pilih;
			printf("List of columns:\n");
			printf("1. Location 1\n2. Location 2\n3. Price\n4. Rooms\n5. Bathroom\n6. Carpark\n7. Type\n8. Furnish\n");
			printf("Choose column to search: ");
			scanf("%d", &pilih);
			if(pilih < 1 || pilih > 8)
			{
				printf("Unknown column!\n");
				break;
			}
			linearSearchStr(pilih);
			puts("");
		}
		
		else if(select == 3)
		{
			system("cls");
			int len = total;
			puts("");
			printf("List of columns:\n");
			printf("1. Location 1\n2. Location 2\n3. Price\n4. Rooms\n5. Bathroom\n6. Carpark\n7. Type\n8. Furnish\n");
			printf("Choose column to sort: ");
			
			int kolomPilih, decision, dsp = 10;
			scanf("%d", &kolomPilih);
			
			int* kolom3 = &kolomPilih;
			
			puts("");
			printf("Sort ascending or descending?:\n");
			printf("1. ascending\n2. descending\n");
			printf("Your choice: ");
			scanf("%d", &decision);
			
			int* deci = &decision;
			puts("");
			
			mergeSort(data, len, kolom3, deci);
			
			printData(dsp);
			
		puts("");
 		}
 		else if (select == 4)
 		{
 			system("cls");
 			exportData();
 			puts("");
		 }
 	}
		while(select >= 1 && select <= 4);
	
	return 0;
	}




