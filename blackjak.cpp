#include <stdio.h>
//2798
int um[100];
int ummmmm(int umm,int umjunsik)
{

    int ummm = 0;
    for (int how = 0; how < umm; how ++)
    {
        for (int person = how + 1; person < umm; person ++)
        {
            for (int is_named = person + 1; is_named < umm; is_named ++)
            {

                if (um[how]+um[person]+um[is_named] == umjunsik) return umjunsik;
                //이 한 줄을 위한 빌드업




                else if (um[how]+um[person]+um[is_named] < umjunsik && um[how]+um[person]+um[is_named] > ummm)
                {
                    ummm = um[how]+um[person]+um[is_named];
                }
                
            }
        }
    }
    return ummm;
}



int main()
{
    int umm,umjunsik;
    scanf("%d %d",&umm,&umjunsik);
    for (int ummm = 0; ummm < umm; ummm ++)
    {
        scanf("%d",&um[ummm]);
    }
    printf("%d",ummmmm(umm,umjunsik));

}