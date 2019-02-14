#include <stdio.h>
#include<math.h>

#define ROW 500
#define COL 500

int row,col,maxgray;
int in_image [ROW][COL];
int out_image [ROW][COL];

int ROWS, COLS;


int read(char *filename)
{
    int i,j,nl=0;
    char ch;
    FILE *fp;
    fp=fopen(filename,"rb");

// Extracting Header information
    while (nl<2)
    {
        fscanf(fp, "%c",&ch);
        if (ch=='\n')
            nl++;
    }
    fscanf(fp,"%d%d%d",&col,&row,&maxgray);

    // Reading data from file
    for(i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            fscanf (fp, "%d", &in_image[i][j]);

        }
    }
    fclose(fp);
}

int write(char *filename)
{
    int i,j,nl=0;
    char ch;
    FILE *fp;
    fp=fopen(filename,"wb");

// Writing header into fp
    fprintf (fp,"%s\n%s\n%d %d\n%d\n",
             "P2","# Created By Mostafiz",col,row,255);

    //Putting data into another file
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            fprintf(fp, "%d ", out_image[i][j]);
        }
        fprintf (fp,"%s","\n");
    }


    fclose(fp);

}

int main()
{


    int i,j;
    int b;
    printf("Enter the value of b(Bias) : ");
    scanf("%d",&b);
    read("abcd.pgm");

    ///Processing the image
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            out_image[i][j] = in_image[i][j] + b;

            if(out_image[i][j] > 255)
            {
                out_image[i][j] = 255;
            }
            else if(out_image[i][j] < 0)
            {
                out_image[i][j] = 0;
            }

        }
    }

    write("1.Brightness.pgm");


    return 0;


}

