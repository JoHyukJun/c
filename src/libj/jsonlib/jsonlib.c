#include "jsonlib.h"


int print_jsonlib()
{
    printf("JSONLIB\n");

    return 0;
}

int json_open(filename)
const char *filename;
{
    int fd;

    fd = open(filename, O_RDONLY);

    if (fd == -1)
    {
        perror("open()");

        return (-1);
    }

    return (fd);
}

int json_close(fd)
int fd;
{
    if (close(fd) == -1)
    {
        perror("close()");

        return (-1);
    }

    return (0);
}

int json_read(fd, buf, size)
int fd;
char *buf;
int size;
{
    int read_size;

    read_size = read(fd, buf, size);

    if (read_size == -1)
    {
        perror("read()");

        return (-1);
    }

    return (read_size);
}

// JSON 문자열에서 특정 키의 값을 추출하는 재귀 함수
int json_get_element_recursive(json_str, key, value)
const char *json_str;
const char *key;
char *value;
{
    char *p = json_str;
    char *q;
    int key_len = strlen(key);

    while ((p = strstr(p, key)) != NULL)
    {
        // 키 앞에 따옴표가 있는지 확인
        if (*(p - 1) == '"' && *(p + key_len) == '"')
        {
            p += key_len + 1;

            // 키 뒤의 ':'를 찾음
            p = strchr(p, ':');
            if (p == NULL)
            {
                return -1;
            }

            p++;

            // 공백을 건너뜀
            while (*p == ' ')
            {
                p++;
            }

            // 값이 문자열인지 확인
            if (*p == '"')
            {
                p++;
                q = value;

                // 문자열 값을 복사
                while (*p != '"' && *p != '\0')
                {
                    *q = *p;
                    p++;
                    q++;
                }

                *q = '\0';

                if (*p != '"')
                {
                    return -1; // 문자열이 제대로 끝나지 않음
                }

                return 0;
            }
            else if (*p == '{')
            {
                // 중첩된 객체를 처리
                int brace_count = 1;
                q = value;

                *q = *p;
                p++;
                q++;

                while (brace_count > 0 && *p != '\0')
                {
                    if (*p == '{')
                    {
                        brace_count++;
                    }
                    else if (*p == '}')
                    {
                        brace_count--;
                    }
                    *q = *p;
                    p++;
                    q++;
                }

                *q = '\0';

                if (brace_count != 0)
                {
                    return -1; // 중첩된 객체가 제대로 끝나지 않음
                }

                return 0;
            }
            else
            {
                // 문자열이 아닌 값을 처리
                q = value;

                while (*p != ',' && *p != '}' && *p != '\0')
                {
                    *q = *p;
                    p++;
                    q++;
                }

                *q = '\0';

                return 0;
            }
        }

        p += key_len;
    }

    return -1; // 키를 찾지 못함
}

int json_get_element(int fd, const char *key, char *value) {
    char buf[1024];
    int read_size;

    lseek(fd, 0, SEEK_SET);

    read_size = read(fd, buf, sizeof(buf) - 1);

    if (read_size == -1) {
        perror("read()");
        return -1;
    }

    buf[read_size] = '\0';

    return json_get_element_recursive(buf, key, value);
}