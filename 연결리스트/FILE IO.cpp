//void inputFile(void)
//{
//	char fileName[BUFSIZ], line[BUFSIZ];
//	FILE *file;
//
//	printf("파일 이름? ");
//	scanf("%s", &fileName);
//
//	file = fopen(fileName, "r");
//	if (file == NULL) {
//		printf("file open error\n");
//		exit(EXIT_FAILURE);
//	}

	while (fgets(line, sizeof(line), file)) {
		char *ptr = strtok(line, delimiter);
		if (ptr == NULL) continue;
		do {
			if (isStartWithAlphabet(ptr)) {
				toLower(&ptr);
				insertNode(&headNodes[ptr[0] - 'a'], ptr);
			}
		} while ((ptr = strtok(NULL, delimiter)) != NULL);
	}

//
//void outputFile(void)
//{
//	char fileName[BUFSIZ], line[BUFSIZ];
//	int count = 0;
//	FILE *file;
//	struct node *ptr;
//
//	printf("파일 이름? ");
//	scanf("%s", &fileName);
//
//	file = fopen(fileName, "wt");
//	if (file == NULL) {
//		printf("file open error\n");
//		exit(EXIT_FAILURE);
//	}
//
//	for (int i = 0; i < MAX_LEN; i++) {
//		if (headNodes[i] != NULL) {
//			for (ptr = headNodes[i]; ptr; ptr = ptr->next) {
//				fprintf(file, "%s: %d\n", ptr->term, ptr->frequency);
//				count++;
//			}
//		}
//	}
//	fprintf(file, "전체 단어 수: %d", count);
//}