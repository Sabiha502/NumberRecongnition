#include<stdio.h>
#
char name[50];
int two(int num)
{
    if (num>=20&&num<30)
    {
        printf("twen");
    }
    else
        printf("no");
    return 0;
}
int three(int num)
{
    if (num>=30&&num<40)
    {
        printf("thir");
    }
    return 0;
}
int five(int num)
{
    if (num>=50 && num<50)
    {
        printf("fif");
    }
    return 0;
}
int twotenth(int num,int d)
{
    if (d>=20&&d<30)
    {
        printf("twen");
    }
}
int threetenth(int num,int d)
{
    if (d>=30&&d<40)
    {
        printf("thir");
    }
}
int fivetenth(int num,int d)
{
    if (d>=50&&d<60)
    {
        printf("fif");
    }
}
struct User
{
    char student_id[10];
    char name[50];
    char password[50];
};


int registe();
int login();

int registe()
{
    printf ("   PLEASE  REGISTER \n");
    printf("--------******-----****----------\n");
    printf("\n");
    char password[50];
    char name[50];
    char student_id[10];
    FILE *log;

    log = fopen("login.txt", "a");
    struct User p;
    printf("                                |\n");
    printf("      Student ID :");
    scanf("%s", p.student_id);
    printf("                                |\n");
    printf("      Student Name:");
    scanf("%s", p.name);
    printf("                                |\n");
    printf("      Password:");
    scanf("%s", p.password);
    printf("                                |\n");
    printf("---------******---------*****----\n");

    fwrite(&p, sizeof(p), 1, log);
    fclose(log);

    printf("\nYour data is taken.\n");
    getchar();
    return 1;
}

int login()
{
    printf("\n      PLEASE LOG IN \n");
    printf("--------******-----****----------\n");
    char password[50];
    char name[50];
    char student_id[10];
    FILE *log;

    log = fopen("login.txt", "r");
    struct User p;
    printf("                                |\n");

    printf("         Student ID :");
    scanf("%s", student_id);
    printf("                                |\n");
    printf("         Password :");
    scanf("%s", password);
    printf("---------******---------*****----\n");
    int match_found=0;
    while (fread(&p, sizeof(p), 1, log))
    {
        if (strcmp(student_id, p.student_id) == 0 && strcmp(password, p.password) == 0)
        {

            match_found=1;
        }
    }

    fclose(log);
    if(match_found==1)
    {
        printf("        logged in successfully\n");
    }
    else
    {
        printf("     invalid id and password\n");
        printf("     Please, Create new account");
    }

    return match_found;
}

void interface()
{
    printf("\n");
    printf("...............Welcome to our Number Recognition System...............");
    printf("\n");
    printf("_______________________________________________________________________");
    printf("\n");
    printf("**e.g : Please, enter the number between 1 to 1,00,000");
    printf("\n");
    printf("\n");
    printf("        Enter The Number : ");
}

void result()
{
    int num;
    char name[][10]= { " "," one","two","three","four","five","six","seven","eight","nine","ten"};
    scanf("%d",&num);
    printf("\n");
    printf("      The numbers in words : ");
    int p= num/10;
    int s=10*p;
    int r =num -s;

    int b=num/100;
    int c =b*100;
    int d= num - c;
    int e=(d/10);
    int k =e*10;
    int f =d-k;

    if (num >10 && num <20)
    {
        if (num==12)
            printf("twelve");
        if (num==11)
            printf("eleven");
        if (num==13)
            printf ("thirteen");
        if (num ==15)
            printf("fifteen");
        if ((num>13 && num<15)||(num>16 && num<20))
            printf("%steen",name[r]);
    }


    if (num<100)
    {


        if  (p>=2 && p<3 )
        {
            two(num);
            printf("ty %s",name[r]);
        }
        if  (p>=3 && p<4 )
        {
            three(num);

            printf("ty %s",name[r]);
        }
        if  (p==4||p==6||p==7||p==9||p==8)
        {
            printf("%s",name[p]);
            printf("ty %s",name[r]);

        }

        if  (p>=5&& num<6 )
        {
            five(num);

            printf("ty %s",name[r]);
        }
    }



    if (num >=100 && num<1000)
    {
        printf ("%shundred ",name[b]);


        if (d >10 &&  d<20)
        {
            if (d==12)
                printf("twelve");
            if (d==11)
                printf("eleven");
            if (d==13)
                printf ("thirteen");
            if (d>13 && d<20)
                printf("%steen",name[f]);
        }
        if (d<=10)
        {
            printf ("%s",name[d]);
        }

        if  (d>=20 && d<30 )
        {
            twotenth(num,d);

            printf("ty %s",name[d]);
            printf("%s",name[f]);
        }
        if  (d>=30 && d<40 )
        {
            threetenth(num,d);

            printf("ty %s",name[d]);
            printf("%s",name[f]);
        }


        if  (d>=50 && d<60 )
        {
            fivetenth(num,d);

            printf("ty");
            printf("%s",name[f]);
        }


        if  ((d>=39 && d<49) ||(d>=59 && d<=100))
        {
            printf("%s",name[e]);
            printf("ty %s",name[f]);
        }
    }
    if (num>999 && num<9999)

    {
        int q =num /1000;
        int t=q*1000;
        int a=num -t;
        int g= a/100;
        int h=g*100;
        int i = a-h;
        int j=i/10;
        int l=j*10;
        int m= i-l;

        printf ("%s thousand",name[q]);
        printf(" %s hundred ",name[g]);
        if (i>=20 && i<30 )
        {
            printf("twenty");
            printf("%s",name[m]);
        }
        if (i>=30 && i<40 )
        {
            printf("thirty");
            printf("%s",name[m]);
        }
        if (i>=50 && i<60 )
        {
            printf("fifty");
            printf("%s",name[m]);
        }

        if ((i>39 && i<49)||(i>59 && i<99))
        {
            printf("%sty ",name[j]);
            printf(" %s",name[m]);
        }
    }
    if (num>9999 && num <99999)
    {
        int n =num /1000;
        int ca = n-10;
        int bd=n/10;
        int mp=bd*10;
        int cmp=n -mp;
        int u=n*1000;
        int v=num -u;
        int w= v/100;
        int x=w*100;
        int y = v-x;
        int z=y/10;
        int ab=z*10;
        int bc= y-ab;



        if (n>9 && n<20)
        {
            if(n==10)
                printf("ten thousand");

            if(n==11)
                printf ("eleven thousand ");
            if(n==12)
                printf ("twelve thousand ");
            if (n==13)
                printf ("thirteen thousand");
            if (n>13 && n <20)
                printf(" %steen thousand ",name[ca]);
                printf ("  %s hundred ",name[w]);

            if (z>=2 && z<=3)
            {
                printf("twenty");
            }
            if ((z>=4 && z<5)||(z>5&&z<10))
            {
                printf("%sty",name[z]);
            }

            if (z>=3 && z<=4)
            {
                printf("thirty");
            }
            if (z>4 && z<=5)
            {
                printf("fifty");
            }
            printf ("%s ",name[bc]);
        }

        if (n>19 && n <30 )
        {
            printf ("twenty %s thousand  ",name[cmp]);
            printf ("%s hundred  ",name[w]);
            if (z>=2 && z<3)
            {
                printf("twenty");
            }
            if (z>=3 && z<4)
            {
                printf("thirty");
            }
            if (z>=5 && z<6)
            {
                printf("fifty");
            }
            if ((z>=4 && z<5)|| (z>=6 && z <9))
            {
                printf("%sty",name[z]);
            }
            printf ("%s ",name[bc]);
        }
        if (n>29 && n <40 )
        {
            printf ("thirty %s thousand  ",name[cmp]);
            printf ("%s hundred  ",name[w]);
            if (z>=2 && z<3)
            {
                printf("twenty");
            }
            if (z>=3 && z<4)
            {
                printf("thirty");
            }
            if (z>=5 && z<6)
            {
                printf("fifty");
            }
            if ((z>=4 && z<5)|| (z>=6 && z <9))
            {
                printf("%sty",name[z]);
            }
            printf ("%s ",name[bc]);
        }
        if (n>49 && n <60 )
        {
            printf ("fifty %s thousand  ",name[cmp]);
            printf ("%s hundred  ",name[w]);
            if (z>=2 && z<3)
            {
                printf("twenty");
            }
            if (z>=3 && z<4)
            {
                printf("thirty");
            }
            if (z>=5 && z<6)
            {
                printf("fifty");
            }
            if ((z>=4 && z<5)|| (z>=6 && z <9))
            {
                printf("%sty",name[z]);
            }
            printf ("%s ",name[bc]);
        }

        if ((n>39 && n <50)||(n>50 && n <100) )
        {
            printf (" %sty %s thousand  ",name[bd],name[cmp]);
            printf ("%s hundred  ",name[w]);
            if (z>=2 && z<3)
            {
                printf("twenty");
            }
            if (z>=3 && z<4)
            {
                printf("thirty");
            }
            if (z>=5 && z<6)
            {
                printf("fifty");
            }
            if ((z>=4 && z<5)|| (z>=6 && z <9))
            {
                printf("%sty",name[z]);
            }
            printf ("%s ",name[bc]);
        }

    }
}

int main ()
{

    int choice;
    printf("\n\n");
    printf("...............Welcome to our Number Recognition System...............");
    printf("\n");
    printf("_______________________________________________________________________");
    printf("\n");
    printf("                    Please Login First...                             |\n\n");
    printf("                     To Login Press 1...                              |\n\n");
    printf("                Don't have an account,Press 2....                     |\n");
    printf("_______________________________________________________________________\n");
    printf("\n\n\n");
    printf("           => Enter your choice here : ");
    scanf("%d", &choice);
    printf("\n");
    int token = 0;
    if (choice == 1)
    {
        token = login();
    }
    else if (choice == 2)
    {
        token = registe();
    }
    else
    {
        printf("Invalid choice.\n");
    }

    if(token)
    {
        system("cls");
        printf("\n\n");
        for( ;1; )
        {
            interface();
            result();
            int now;
            printf("\n_______________________________________________________________________");
            printf("\n\n         Want to try another.. press 1");
            printf("\n           Close the application.. press 2");
            printf("\n\n         Enter youe choice : ");
            scanf("%d",&now);
            if(now == 2)
                return 0;
            else if(now)
                system("cls");
        }
    }

}
