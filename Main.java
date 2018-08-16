import java.util.Scanner;

public class Main {
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        int n;

        System.out.println("Для получения n-го числа Фибоначчи, введите n: ");
        n = input.nextInt();

        System.out.println("n-е число Фибоначчи: " + fibonacci(n));


    }


    static int[][] multiplyMatrics(int[][] matr1, int[][] matr2){

        int[][] matr = new int[2][2];
        matr[0][0] = matr1[0][0]*matr2[0][0] + matr1[0][1] * matr2[1][0];
        matr[0][1] = matr1[0][0]*matr2[0][1] + matr1[0][1] * matr2[1][1];
        matr[1][0] = matr1[1][0]*matr2[0][0] + matr1[1][1] * matr2[1][0];
        matr[1][1] = matr1[1][0]*matr2[0][1] + matr1[1][1] * matr2[1][1];

        return matr;
    }


    static int[][] power(int [][] matr, int pow){

        if(pow == 0) {
            for(int i=0; i < 2; i++){
                for(int j=0; j < 2; j++){
                    matr[i][j]=1;
                }
            }
            return matr;
        }

        else if(pow == 1) return matr;

        else if(pow%2==1){
            return multiplyMatrics(matr, power(multiplyMatrics(matr, matr), pow/2));
        }
        else {
            return power(multiplyMatrics(matr,matr), pow/2);
        }
    }

    static int fibonacci(int n){
        int[][] matr = new int[2][2];
        matr[0][0] = 1;
        matr[0][1] = 1;
        matr[1][0] = 1;
        matr[1][1] = 0;

        return power(matr,n-1)[0][0];
    }
}


