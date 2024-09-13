void menu() {
	printf("*************«Î—°‘Ò*****************\n");
	printf("*************1.PVP******************\n");
	printf("*************2.Play with PC*********\n");
	printf("************************************\n");
}
int choosemode() {
	int mode;
	scanf_s("%d", &mode);
	return mode;
}
void showchess(int arr[][Maxsize], int hang, int lie) {
	if (hang <= 9)
		printf("%d ", hang);
	else
		printf("%d", hang);
	for (int i = 1; i <= lie; i++) {
		if (arr[hang][i] == 0)
			printf("  ");
		if (arr[hang][i] == 1)
			printf("°Ò ");
		if (arr[hang][i] == 2)
			printf("° ");
	}
	printf("\n");
}
void displayboard(int arr[][Maxsize], int hang, int lie) {
	printf(" ");
	for (int i = 1; i <= lie; i++) {
		if (i <= 9) {
			printf(" %d", i);
		}
		else
			printf("%d", i);
	}
	printf("\n ©∞ ");
	for (int i = 1; i < lie; i++) {
		printf("©– ");
	}
	printf("©¥\n");
	for (int i = 1; i < hang; i++) {
		showchess(arr, i, lie);
		printf(" ©¿ ");
		for (int j = 1; j < lie; j++) {
			printf("©‡ ");
		}
		printf("©»\n");
	}
	showchess(arr, hang, lie);
	printf(" ©∏ ");
	for (int j = 1; j < lie; j++) {
		printf("©ÿ ");
	}
	printf("©º\n");

}
void player(int hang, int lie, int player, int arr[][Maxsize]) {
	if (player == 1) {
		arr[hang][lie] = 1;
	}
	if (player == 2) {
		arr[hang][lie] = 2;
	}
}
int checkx(int arr[][Maxsize], int hang, int lie, int num) {
	dir[0] = 0;
	int i = hang, j = lie, t = 0;
	while (arr[i][j] == num) {
		t++;
		j--;
	}
	int c = arr[i][j];
	j = lie + 1;
	while (arr[i][j] == num) {
		t++;
		j++;
	}
	if ((arr[i][j] == 2 || c == 2) && t == 4) dir[0] = 1;
	return t;
}
int checky(int arr[][Maxsize], int hang, int lie, int num) {
	dir[1] = 0;
	int i = hang, j = lie, t = 0;
	while (arr[i][j] == num) {
		t++;
		i--;
	}
	int c = arr[i][j];
	i = hang + 1;
	while (arr[i][j] == num) {
		t++;
		i++;
	}
	if ((arr[i][j] == 2 || c == 2) && t == 4) dir[1] = 1;
	return t;
}
int checkz1(int arr[][Maxsize], int hang, int lie, int num) {
	dir[2] = 0;
	int i = hang, j = lie, t = 0;
	while (arr[i][j] == num) {
		t++;
		j--;
		i--;
	}
	int c = arr[i][j];
	i = hang + 1;
	j = lie + 1;
	while (arr[i][j] == num) {
		t++;
		j++;
		i++;
	}
	if ((arr[i][j] == 2 || c == 2) && t == 4) dir[2] = 1;
	return t;
}
int checkz2(int arr[][Maxsize], int hang, int lie, int num) {
	dir[3] = 0;
	int i = hang, j = lie, t = 0;
	while (arr[i][j] == num) {
		t++;
		j--;
		i++;
	}
	int c = arr[i][j];
	j = lie + 1;
	i = hang - 1;
	while (arr[i][j] == num) {
		t++;
		j++;
		i--;
	}
	if ((arr[i][j] == 2 || c == 2) && t == 4) dir[3] = 1;
	return t;
}
int checkit(int arr[][Maxsize], int hang, int lie, int num) {
	int x = checkx(arr, hang, lie, num);
	int y = checky(arr, hang, lie, num);
	int z1 = checkz1(arr, hang, lie, num);
	int z2 = checkz2(arr, hang, lie, num);
	int max = 0;
	maxd = 0;
	if (max < x) {
		maxd = 0;
		max = x;
	}
	if (max < y) {
		maxd = 1;
		max = y;
	}
	if (max < z1) {
		maxd = 2;
		max = z1;
	}
	if (max < z2) {
		maxd = 3;
		max = z2;
	}
	return max;
}
