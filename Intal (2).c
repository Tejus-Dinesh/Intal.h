#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* stripzeros(char* intalx,int n)
{
    
    int count = 0;
    for (int i = 0; i < n; i++)
    {
    if(intalx[i] == '0')
        count++;
    
    else
        break;
    
    }
    for (int i = 0; i < n; i++)
    {
        intalx[i] = intalx[i+count];
    }

    intalx[n-count+1] = '\0';

    return intalx;

}

char* intal_add(const char* intal1, const char* intal2)
{
    int len_intal1 = strlen(intal1);
    int len_intal2 = strlen(intal2);
    int tmp,i,j = 0,sum,carry = 0;
    char *int1,*int2,*answer;

    if(len_intal2<len_intal1)
    {
        int1 = malloc(sizeof(char)*len_intal2+1);
        int2 = malloc(sizeof(char)*len_intal1+1);
        strcpy(int1,intal2);
        strcpy(int2,intal1);
        tmp = len_intal1;
        len_intal1 = len_intal2;
        len_intal2 = tmp;

    }
    else
    {
        int1 = malloc(sizeof(char)*len_intal1+1);
        int2 = malloc(sizeof(char)*len_intal2+1);
        strcpy(int1,intal1);
        strcpy(int2,intal2);
        
    }
    
    answer = malloc(sizeof(char)*strlen(int2)+2);

    for(i = len_intal1;i>0;i--)
    {
        sum = (int1[--len_intal1]-48) + (int2[--len_intal2]-48) + carry;
        answer[j++] = (sum%10)+48; 
        carry = sum /10;

    }
    for ( i = len_intal2; i>0; i--)
    {
        sum = (int2[--len_intal2]-48) + carry;
        answer[j++] = (sum%10)+48; 
        carry = sum /10;
    }
    if(carry)
    {
        answer[j++] = carry+48;
    }
    answer[j]  = '\0';
   
    int x = strlen(answer);
    char *temp = malloc(sizeof(char)*x+1);
   
    for(i = 0; i < strlen(answer);i++)
    {
        temp[i] = answer[--x];
    }
    
   
    temp[i] = '\0';
    free(int1);
    free(int2);
    free(answer);
    

    return temp;
}

int intal_compare(const char* intal1, const char* intal2)
{
    int len_intal1 = strlen(intal1);
    int len_intal2 = strlen(intal2);

    int i;
    if(len_intal2 > len_intal1)
        return -1;
    else if (len_intal1 > len_intal2)
        return 1;
        
    else
    {
        for(i = 0; i < len_intal2;i++)
        {
            if (intal1[i] < intal2[i])
                return -1;
            else if (intal1[i] > intal2[i])
                return 1;
            else
                continue;                  
        }
        return 0;
    }
    
    
}

char* intal_diff(const char* intal1, const char* intal2)
{
    int x = intal_compare(intal1, intal2);
    char *diff1,*diff2;
    int len_intal1,len_intal2,borrow = 0,j = 0,i;
    
    if(x == 0)
    {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    } 
    else if(x == -1)
    {
        diff1 = malloc(sizeof(char)*(strlen(intal2)+1));
        diff2 = malloc(sizeof(char)*(strlen(intal1)+1));
        strcpy(diff1,intal2);
        strcpy(diff2,intal1);
        len_intal1 = strlen(intal2);
        len_intal2 = strlen(intal1);    
    }
    else
    {

        diff1 = malloc(sizeof(char)*(strlen(intal1)+1));
        diff2 = malloc(sizeof(char)*(strlen(intal2)+1));
        strcpy(diff1,intal1);
        strcpy(diff2,intal2);
        len_intal1 = strlen(intal1);
        len_intal2 = strlen(intal2); 
    }
    char *result = malloc(sizeof(char)*(len_intal1+1));
   

    for(i = len_intal2; i > 0 ;i--)
    {
        x = (diff1[--len_intal1] - 48) - (diff2[--len_intal2]-48) - borrow;

        if(x<0)
        {
            x = x+10;
            borrow = 1;
        }
        else
            borrow = 0;
            
        result[j++] = x+48;
    }
   
    for(i = len_intal1-1;i >= 0; i--)
    {
        x =(diff1[i] - 48) - borrow;
        if(x<0)
        {
            x = x+10;
            borrow = 1;
        }
        else  
            borrow = 0;
    result[j++] = x+48;
    }
        
     
    result[j] = '\0';
    
    x = strlen(result);
    

    char *temp = malloc(sizeof(char)*(x+1));
    

    for(i = 0; i < strlen(result);i++)
    {

        temp[i] = result[--x];

    }
    temp[i] = '\0';
   int zero=strlen(temp);
  int count=0;
  for(int i=0;i<zero;i++){

    if(temp[i]=='0'){

        count++;
    }
    else{
        break;
    }
  }
  char *New_result=malloc(sizeof(char)*((strlen(temp)-count)+1));
  int z = 0;
  if(count==zero)
  {
    char*g=malloc(sizeof(char)*2);
    g[0]='0';
    g[1]='\0';
    return g;
  }
  else
  {
    for( j = count;j <= zero;j++)
    {
        New_result[z]=temp[j];
        z++;
    }
  }
    
    free(diff1);
    free(diff2); 
    free(result);
    free(temp);
    return New_result;
}

char* intal_multiply(const char* intal1, const char* intal2)
{

    int i,j,temp,f_length;
    int length_intal1 = strlen(intal1);
    int length_intal2 = strlen(intal2);
    int *mul1 = malloc(sizeof(int)*length_intal1);
    int *mul2 = malloc(sizeof(int)*length_intal2);
    int *result = calloc((length_intal1 + length_intal2 + 1),sizeof(int));
    
    for(i = length_intal2-1,j=0;i>=0;i--,j++)
            mul2[j] = intal2[i]-48;


    for(i = length_intal1-1,j=0;i>=0;i--,j++)
            mul1[j] = intal1[i]-48;

    
    for(i = 0;i < length_intal2;i++)
        {
           
            for(j = 0;j < length_intal1;j++)
                result[i+j] += mul2[i]*mul1[j];

            
        }
        for(i = 0;i < (length_intal1+length_intal2);i++)
        {
            temp = result[i]/10;
            result[i] = result[i]%10;
            result[i+1] = result[i+1] + temp;

        }
        for(; i>= 0;i--)
        {
            if(result[i] >=0 && result[i] <=9)
                break;
        }
    f_length = i;
    char *finalresult = calloc(f_length+1,sizeof(int));
    for(j=0;i >= 0;i--,j++)
    {
        if(result[i] >=0 && result[i] <=9)
            finalresult[j] = result[i] + '0';
        else
        {
            finalresult[j] = '\0';
            break;
        }

    }
    free(result);
    free(mul1);
    free(mul2);
    finalresult = stripzeros(finalresult,f_length);
    return finalresult;
}

char* intal_mod(const char* intal1, const char* intal2)
{
    if(intal_compare(intal1,intal2)==-1)
    {
        char *answer = malloc(sizeof(char)*(strlen(intal1)+1));
        strcpy(answer,intal1);
        return answer;
    }
    char *result=(char *)malloc(sizeof(char)*(strlen(intal2)+1));
    char *div=calloc(1001, sizeof(char));
    int i=0;
    while(intal1[i]!='\0')
    {
        while(intal_compare(div,intal2)==-1)
        {
            char temp[2];
            temp[0]=intal1[i];
            temp[1]='\0';
            if(intal_compare(div,"0")==0)
                strcpy(div,temp);
            else
                strcat(div,temp);
            i++;
        }
        while(intal_compare(div,intal2)!=-1)
            strcpy(div,intal_diff(div,intal2));
        
    }
    strcpy(result,div);
    free(div);
    return result;

}

char* intal_pow(const char* intal1, unsigned int n)
{
    char *base = malloc(sizeof(char)*(strlen(intal1)+1));
    strcpy(base,intal1);
    
    char *result = malloc(sizeof(char)*2);
    result[0] = '1';
    result[1] = '\0';
    if (n == 0)
    {
        char *answer = malloc(sizeof(char)*2);
        answer[0] = '1';
        answer[1] = '\0';
        return answer;
    }
    while(n >0 )
    {
        if(n%2 == 0)
        {
            char *temp = intal_multiply(base,base);
            char *temp_1 = base;
            base = temp;
            free(temp_1);
            n = n/2;
  
        }
        else
        {
            
            char *temp_2 = intal_multiply(base,result);
            char *temp_3 = result;
            result = temp_2;
            free(temp_3);
            n = n-1;
           
        }
    }
        free(base);
       
       return result;
        
}

char* intal_gcd(const char* intal1, const char* intal2) 
{
    int len_intal1 = strlen(intal1);
    int len_intal2 = strlen(intal2);
    int x = intal_compare(intal1,"0");
    int y = intal_compare(intal2,"0");
    char *temp;
    if(x==0 || y==0)
    {
        char *answer = malloc(sizeof(char)*2);
        answer[0]='0';
        answer[1]='\0';
        return answer;
    }
        char *gcdintal1 =malloc(sizeof(char)*(len_intal1+1));
        char *gcdintal2 = malloc(sizeof(char)*(len_intal2+1));
        strcpy(gcdintal1, intal1);
        strcpy(gcdintal2, intal2);
        while(intal_compare(gcdintal2,"0")!=0)
    {
        temp = gcdintal1;
        gcdintal1 = gcdintal2;
        gcdintal2 = intal_mod(temp,gcdintal2);
        free(temp);
        temp=NULL;
    }
    free(gcdintal2);
    gcdintal2=NULL;

    return gcdintal1;

}

char* intal_fibonacci(unsigned int n)
{
    char *fib_c;
    char *temp = malloc(sizeof(char)*2);
    temp[0] = '0';
    temp[1] = '\0';
    if (n == 0)
    {    
        return temp;
    }
    else if (n == 1)
    {
        temp[0] = '1';
        temp[1] = '\0';
        return temp;
    }
    char *fib_a = "0";
    char *fib_b = "1";
    int i;
    
    for(i = 2; i < n+1;i++)
    {
        fib_c = intal_add(fib_a,fib_b);
        fib_a = fib_b;
        fib_b = fib_c;

    }
    fib_b = NULL;
    fib_a = NULL;
    free(fib_a);
    free(fib_b);
   
    return fib_c;
}

char* intal_factorial(unsigned int n)
{
    char *add1 = malloc(sizeof(char)*2);
    add1[0] = '1';
    add1[1] = '\0';
    if(n == 0 || n == 1)
        return add1;

  char  *result = (char*)malloc(2 * sizeof(char));
  result[0] = '1';
  result[1] = '\0';

  char* add2= (char*)malloc(2 * sizeof(char));
  add2[0] = '1';
  add2[1] = '\0';

  for(int i = 1; i <n; ++i) 
  {
    add1 = intal_add(add1, add2);
    result = intal_multiply(add1, result);
  } 
  free(add2);
  free(add1);
  return result;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
    if(n == 0)
    {
        char *answer = malloc(sizeof(char)*2);
        answer[0] ='0';
        answer[1] = '\0';
        return answer;
    }
    if(k > n-k)
        k = n-k;
    int i,j,x;
    char **arr = (char**) malloc((k+1) * sizeof(char*));
    for(int i = 0; i < k + 1; ++i)
    {
        arr[i] = (char*)malloc(2 * sizeof(char));
        arr[i][0] = '0';
        arr[i][1] = '\0';
    }
    arr[0][0] = '1';

    for(i = 1; i <= n; i++)
    {
        if(i<k)
            x = i;
        else
            x = k;
        for(j = x;j > 0; j--)
        {
                char *temp = intal_add(arr[j],arr[j-1]);
                char *temp_1 = arr[j];
                arr[j] = temp;
                free(temp_1);
        }
                    
}   
    char *answer = malloc(sizeof(char)*strlen(arr[k])+1);
    strcpy(answer,arr[k]);
    for(i = 0; i < k+1; i++)
        free(arr[i]);
    free(arr);

        return answer;
}

int intal_max(char **arr, int n)
{
    int i,x,offset = 0;

    for(i = 0;i<n;i++)
    {   
        x = intal_compare(arr[i],arr[offset]);
        if(x == 1)
        {
            offset = i;
        }        

    }

    return offset;
}

int intal_min(char **arr, int n)
{
    int i,x,offset = 0;

    for(i = 0;i<n;i++)
    {   
        x = intal_compare(arr[i],arr[offset]);
        if(x == -1)
        {
            offset = i;
        }        

    }

    return offset;
}

int intal_search(char **arr, int n, const char* key)
{
    int i,x;
    for(i = 0; i < n; i++)
    {
        x = intal_compare(arr[i],key);
        if(x==0)
            return i;

    }
    return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
    int mid,start, end, x;
    start = 0;
    end = n-1;
    int index = -1;
    while(start<=end)
    {
        mid = start+(end - start)/2;
        x = intal_compare(key,arr[mid]);
        if(x == 0)
        {   
            index = mid;
            end = mid-1;

        }
            
        else if(x == -1)
            end = mid -1;
        else
            start = mid + 1;
    }
    return index;
}
 
static void max_heapify(char **arr, int i , int n)
{
    int left, right , max,x;
    left = 2*i + 1;
    right = 2*i + 2;
    
    if(left <= (n-1))
    {
        x = intal_compare(arr[left],arr[i]);
        if(x == 1)
            max = left;
        else
            max = i;
    }
    else
    {
        max = i;
    }
    
   
    
    if(right <= (n-1))
    {
        x = intal_compare(arr[right],arr[max]);
        if(x ==1 )
            max = right;
    }
    
    if(max != i)
    {
        char *temp;
        temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
        
        max_heapify(arr,max,n);
    }
    
}

void intal_sort(char **arr, int n)
{

    int i;  

    for(i = (n-2)/2 ; i>=0 ; i--)
    {
        max_heapify(arr,i,n);
    }
    for(int i=n-1;i>0;i--)
    {
    
      char *temp;
      temp=arr[0];
      arr[0]=arr[i];
      arr[i]=temp;
      max_heapify(arr,0,i);

    }

}

char* coin_row_problem(char **arr, int n)
{
    if(n == 0)
    {
        char *answer = malloc(sizeof(char)*2);
        answer[0]='0';
        answer[1] = '\0';
        return answer;
    }
      
    int i,x;
    char *prev = malloc(sizeof(char)*2);
    prev[0] = '0';
    prev[1] = '\0';
    char *curr = arr[0];
    char *next,*temp;
    for( i = 2; i <= n; i++)
    {
        
        temp = intal_add(prev,arr[i-1]);
        x =intal_compare(temp,curr);
        if(x == 1)
            next = temp;
        else
            next = curr;


        prev = curr;
        curr = next;
 
  
    }
   
   return curr;

 }












