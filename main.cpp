#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

// 开头一定为Y/N/2
// Y/N 后面肯定是 Y/N/2
// 2之后一定是y/n/1
// y/n之后一定是 y/n/1
// 1之后只能是Y/N/2
bool idTrue(char *s)
{
    if (s[0] != 'Y' && s[0] 'N' && s[0] != '2')
    {
        return false;
    }

    int i = 1;
    while (s[i] != '\0')
    {
        if (s[i] == 'Y' || s[i] == 'N')
        {
            if (s[i + 1] != 'Y' && s[i + 1] != 'N' && s[i + 1] != '2')
                return false;
        }
        else if (s[i] == '2')
        {
            if (s[i + 1] == '\0')
            {
                break;
            }
            if (s[i + 1] != 'y' && s[i + 1] != 'n' && s[i + 1] != '1')
            {
                return false;
            }
        }
        else if (s[i] == 'y' || s[i] == 'n')
        {
            if (s[i + 1] != 'y' && s[i + 1] != 'n' && s[i + 1] != '1')
                return false;
        }
        else if (s[i] == '1')
        {
            if (s[i + 1] == '\0')
            {
                break;
            }
            if (s[i + 1] != 'Y' && s[i + 1] != 'N' && s[i + 1] != '2')
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
}
