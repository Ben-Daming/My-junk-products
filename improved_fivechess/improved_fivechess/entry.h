int board[Maxsize][Maxsize];
int hang, lie, start;
for (int i = 0; i < Maxsize; i++) {
	for (int j = 0; j < Maxsize; j++) {
		board[i][j] = 0;
	}
}
menu();
if (choosemode() == 1) {
	printf("���������̳ߴ磨X��Y�У�\n");
	scanf_s("%d%d", &hang, &lie);
	displayboard(board, hang, lie);
	gaming(board, hang, lie);
}
else {
	printf("���������̳ߴ磨X��Y�У�\n");
	scanf_s("%d%d", &hang, &lie);
	printf("����Ҫ�������廹�Ǻ������壿\n");
	printf("����1���֣�����2����\n");
	scanf_s("%d", &start);
	time += start;
	pcgaming(board, hang, lie);
}
