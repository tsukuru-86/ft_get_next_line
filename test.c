#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

// テスト用のmain関数
int main()
{
    int fd;
    // char *line;
    int line_count = 0;

    // テスト用ファイルを開く
    fd = open("test1.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("ファイルを開けませんでした。\n");
        return 1;
    }

    printf("lineの出力は%s\n", get_next_line(fd));
    printf("lineの出力は%s\n", get_next_line(fd));
    printf("lineの出力は%s\n", get_next_line(fd));
    printf("lineの出力は%s\n", get_next_line(fd));
    printf("lineの出力は%s\n", get_next_line(fd));


    // // get_next_lineを使用してファイルを1行ずつ読み込む
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("行 %d: %s", ++line_count, line);
    //     free(line);
    // }

    // ファイルを閉じる
    close(fd);

    printf("\n合計 %d 行読み込みました。\n", line_count);

    return 0;
}
