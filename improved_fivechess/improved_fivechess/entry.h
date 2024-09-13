int board[Maxsize][Maxsize];
int hang, lie, start;
for (int i = 0; i < Maxsize; i++) {
	for (int j = 0; j < Maxsize; j++) {
		board[i][j] = 0;
	}
}
menu();
if (choosemode() == 1) {
	printf("请输入棋盘尺寸（X行Y列）\n");
	scanf_s("%d%d", &hang, &lie);
	displayboard(board, hang, lie);
	gaming(board, hang, lie);
}
else {
	printf("请输入棋盘尺寸（X行Y列）\n");
	scanf_s("%d%d", &hang, &lie);
	printf("您想要先手下棋还是后手下棋？\n");
	printf("输入1先手，输入2后手\n");
	scanf_s("%d", &start);
	time += start;
	pcgaming(board, hang, lie);
}
