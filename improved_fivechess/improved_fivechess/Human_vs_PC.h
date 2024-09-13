void startup(int arr[][Maxsize], int hang, int lie, int ph, int pl) {
	if (ph > 1 && pl > 1)
		arr[ph - 1][pl - 1] = 2;
	else if (ph > 1 && pl < lie)
		arr[ph - 1][pl + 1] = 2;
	else if (ph < hang && pl < lie)
		arr[ph + 1][pl + 1] = 2;
	else if (ph < hang && pl>1)
		arr[ph + 1][pl - 1] = 2;
	else if (ph > 1)
		arr[ph - 1][pl] = 2;
	else if (pl > 1)
		arr[ph][pl - 1] = 2;
	else if (pl < lie)
		arr[ph][pl + 1] = 2;
	else if (ph < hang)
		arr[ph + 1][pl] = 2;
}
int abs(int a, int b) {
	if (a > b)
		return a - b;
	return b - a;
}
void defend_attack(int arr[][Maxsize], int hang, int lie, int ph, int pl) {
	int maxh1 = 1, maxl1 = 1, max1 = 0, max2 = 0, now1 = 0, now2 = 0, maxh2 = 1, maxl2 = 1;
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				now1 = checkit(arr, i, j, 1);
				if (now1 != 5 && (i == 1 || j == 1 || i == hang || j == lie));
				else if (dir[maxd]);
				else if (now1 > max1) {
					max1 = now1;
					maxh1 = i;
					maxl1 = j;
				}
				else if (now1 == max1 && (abs(i, hang / 2) < abs(maxh1, hang / 2) || abs(j, hang / 2) < abs(maxl1, hang / 2))) {
					max1 = now1;
					maxh1 = i;
					maxl1 = j;
				}
				arr[i][j] = 2;
				now2 = checkit(arr, i, j, 2);
				if (now2 != 5 && (i == 1 || j == 1 || i == hang || j == lie));
				else if (now2 > max2) {
					max2 = now2;
					maxh2 = i;
					maxl2 = j;
				}
				else if (now2 == max2 && (abs(i, hang / 2) < abs(maxh2, hang / 2) || abs(j, hang / 2) < abs(maxl2, hang / 2))) {
					max2 = now2;
					maxh2 = i;
					maxl2 = j;
				}
				arr[i][j] = 0;

			}
		}
	}
	printf("player2:\n");
	if (max1 <= 3 || max1 <= max2) {
		arr[maxh2][maxl2] = 2;
		printf("%d %d\n", maxh2, maxl2);
		if (max2 >= 5) flag = 1;
		return;
	}
	printf("%d %d\n", maxh1, maxl1);
	arr[maxh1][maxl1] = 2;
}
void pcgaming(int arr[][Maxsize], int hang, int lie) {
	if (time == 2) arr[hang / 2][lie / 2] = 2;
	displayboard(arr, hang, lie);
	int ph, pl;
	printf("player1:\n");
	scanf_s("%d%d", &ph, &pl);
	while (arr[ph][pl] != 0) {
		printf("该位置已经有棋子了！\n");
		scanf_s("%d%d", &ph, &pl);
	}
	player(ph, pl, 1, arr);
	if (checkit(arr, ph, pl, 1) >= 5) {
		printf("Player1 Win the Game\n");
		displayboard(arr, hang, lie);
		return;
	}
	if (time == 1) 	startup(arr, hang, lie, ph, pl);
	else  defend_attack(arr, hang, lie, ph, pl);
	time += 2;
	if (flag) {
		printf("PCplayer Win the Game\n");
		displayboard(arr, hang, lie);
		return;
	}
	pcgaming(arr, hang, lie);
}
