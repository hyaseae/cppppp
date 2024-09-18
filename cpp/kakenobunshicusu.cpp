#include <omp.h>
#include <stdio.h>


int prime = 1234567897;

char possible[] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'!','@','#','$','%','^','&','*','(',')',' ','\0',
};
int char_cnt = sizeof(possible) / sizeof(char);

const int LENGTH = 5;
char c[LENGTH];
int guessing[LENGTH];
char now_looking[LENGTH];
int is_end = 0;
// not using iostream here due to output ordering issues

// iostream tends to output each part between <<'s separately to the console, 
// which can lead to random output if multiple threads are doing the same
// thing.

// printf will generally output the whole result string in one go, so results
// of separate printf calls, even from different threads, will remain intact

// Another fix, other than using printf, would be to give each thread its own 
// place to store output temporarily (a stringstream), and then output the whole
// result in one go.
long long int cache[50] = {1};
int pow(int n)
{
    if (cache[n]!= 0)
    {
        return (int)cache[n];
    }
    cache[n] = (pow(n-1)*97)%prime;
    return (int) cache[n];
}
long long int hashing(char c[])
{
    long long int ans = 0;
    for (int i = 0; c[i] != '\0'; i ++)
    {
        int k =((c[i] - '!' + 1) * pow(i)); 
        ans += k;
        ans %= prime;
        //printf("%lld %d %c\n",ans,k,c[i]);
    }
    return (int) ans;
}
void plus_guess(int where)
{
	if (guessing[where] >= char_cnt)
	{
		guessing[where] = 0;
		if (where >= LENGTH)
		{
			return;
		}
		plus_guess(where + 1);
		return;
	}
	guessing[where]++;
}

void change()
{
	for (int i = 0; i < LENGTH; i ++)
	{
		now_looking[i] = possible[guessing[i]];
	}
}

int same()
{
	for (int i = 0; i <LENGTH; i ++)
	{
		if (now_looking[i]!=c[i])
		{
			return false;
		}
	}
	return true;
}

int main() {
	
	scanf("%s",c);
	int hashed = hashing(c);
	printf("\n%s\n%d",c,hashed);
	#pragma omp parallel num_threads(20)
	printf("Hi, I'm thread number %d!\n",omp_get_thread_num());
	
	
	#pragma omp parallel num_threads(20)
	for(int i = 0;i <10000000 ;i++) {
		
		if (is_end)
		{
			break;
		}
		
		
		
		plus_guess(0);
		change();
		
		int maybe = hashing(now_looking);
		if (maybe == hashed)
		{
			printf("\nend:%s real:%s",now_looking,c);
			if (same())
			{
				is_end = 1;
			}
		}
		
		//printf("\nThread number %d, looking %s...",omp_get_thread_num(),now_looking);
	}
	
}