void gaming(int arr[][Maxsize], int hang, int lie) {
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
	displayboard(arr, hang, lie);
	printf("player2:\n");
	scanf_s("%d%d", &ph, &pl);
	while (arr[ph][pl] != 0) {
		printf("该位置已经有棋子了！\n");
		scanf_s("%d%d", &ph, &pl);
	}
	player(ph, pl, 2, arr);
	if (checkit(arr, ph, pl, 2) >= 5) {
		printf("Player2 Win the Game\n");
		displayboard(arr, hang, lie);
		return;
	}
	displayboard(arr, hang, lie);
	gaming(arr, hang, lie);
}
