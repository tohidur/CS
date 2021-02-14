#include<stdio.h>


int main(void)
{

    int a[]={10,20,30,40,50,60};

    int *p[]={a,a+1,a+2,a+3,a+4,a+5}; // array of pointers

    int **pp = p; //pointer to pointer p

    int r=10;

    int *q = &r;

    int **rq = &q;

    printf("facts=========================\n");

    printf("Value of r and address of r is : %d %u\n",r,&r);

    printf("Value of q and address of q is : %d %u\n",q,&q);

    printf("Value of rq and adess of rq is : %d %u\n",rq,&rq);

    printf("--------------------------------\n");

    printf("value of r => r=%d, *q=%d **rq=%u\n",r,*q,**rq);

    printf("addr of r => &r=%u, q=%u *rq=%u\n",&r,q,*rq);

    printf("Value of q => q=%u, *rq=%u\n",q,*rq);

    printf("addre of q => &q=%u, rq=%u\n", &q,rq);

    printf("Value of rq=> rq=%u\n",rq);

    printf("Addre of rq=> &rq=%u\n",&rq);

    //printf("value of *q,*rq,**rq using u are : %u %u %u\n",*q,*rq,**rq);

    printf("=============================================\n");

    printf("Value of a[0] => a[0]=%d\n",a[0]);

    printf("Addre of a => a=%u\n",a);

    printf("Value of p[0] => p[0]=%u\n",p[0]);

    printf("Addre of p => p=%u\n",p);

    printf("Value of pp => pp=%u\n",pp);

    printf("Addre of pp => &pp=%u\n",&pp);

    printf("--------------------------------\n");

    printf("Value of p[0] => p[0]=%u,*pp=%u \n",p[0], *pp);

    printf("Value of a[0] => a[0]=%d,**p=%u, ***pp=%u \n",a[0],**p, **pp);

    printf("===============================================\n");

    printf("address pointed by pp/ address of p %u \n",pp);

    printf("address pointed by p/ address of a %u \n",*p);

    // lets say starts from 100 and each int is 1 byte
    // p pointers addr starts with 200 and each pointer is 2 bytes
    // addr of pp - 300

    // a[3] = *(a+3) = *p[3] = **(p+3) = *(pp + 3)
    // p is aa array and an pointer to array(pp) can be used exactly as array p

    pp++; // pp points to 202

    printf("%d %d %d \n", pp-p, *pp-a, **pp);
    // 1 element | 1 element | 20

    *pp++;
    // 204 then * - 104
    // pp - 204

    printf("%d %d %d \n", pp-p,*pp-a,**pp);
    // 3 | 2  | 30

    ++*pp;
    // 104 is changed to 106

    printf("%d %d %d \n",pp-p, *pp-a,**pp);
    // 2 | 3 | 40

    ++**pp;
    // 40 will be changed to 41

    printf("%d %d %d \n",pp-p, *pp-a,**pp);
    // 
}
