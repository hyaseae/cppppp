#include <cstdio>
#include <functional>
#include <string>

long long int hashed[10][10];
char c[8];
using std::string;
int i,j,ans = 0;

int main()
{
    std::hash<string> str_hash;
    for (i = 0; i < 10; i ++)
    {
        
        for (j = 0; j < 10; j ++)
        {

            scanf("%s",c);
            hashed[i][j] = str_hash(c);
            

        }

    }

    for (i = 0; i < 10; i ++)
    {
        for (j = 0; j < 10; j ++)
        {
            if (hashed[0][i] != hashed[j][i])
            {
                break;
            }
        }
        if (j == 10)
        {
            ans = 1;
        }
    }

    for (i = 0; i < 10; i ++)
    {
        for (j = 0; j < 10; j ++)
        {
            if (hashed[i][0] != hashed[i][j])
            {
                break;
            }
        }
        if (j == 10)
        {
            ans = 1;
        }
    }
    printf("%d",ans);
}