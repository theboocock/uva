import java.util.Scanner;
public class Main{
   public static void main(String[] args){
      Scanner scan = new Scanner(System.in);
      int b1, c1, g1, b2, c2, g2, b3, c3, g3;
      while(scan.hasNextInt()){
         b1 = scan.nextInt();
         g1 = scan.nextInt();
         c1 = scan.nextInt();
         b2 = scan.nextInt();
         g2 = scan.nextInt();
         c2 = scan.nextInt();
         b3 = scan.nextInt();
         g3 = scan.nextInt();
         c3 = scan.nextInt();
         int moves = 0, tempMoves;
         int total;
         String colours = "no solution";
         total = b1+c1+g1+b2+c2+g2+b3+c3+g3;
         
         tempMoves = b1+c2+g3;
         moves = total-tempMoves;
         colours = "BCG";
         
         tempMoves = b1+g2+c3;
         if(moves>(total-tempMoves)){
            moves = total-tempMoves;
            colours = "BGC";
         }
         tempMoves = c1+b2+g3;
         if(moves>(total-tempMoves)){
            moves = total-tempMoves;
            colours = "CBG";
         }
         tempMoves = c1+g2+b3;
         if(moves>(total-tempMoves)){
            moves =total-tempMoves;
            colours = "CGB";
         }
         tempMoves = g1+b2+c3;
         if(moves>(total-tempMoves)){
            moves = total-tempMoves;
            colours = "GBC";
         }
         tempMoves = g1+c2+b3;
         if(moves>(total-tempMoves)){
            moves = total-tempMoves;
            colours = "GCB";
         }
         System.out.println(colours+" "+(moves));
      }
   }
}