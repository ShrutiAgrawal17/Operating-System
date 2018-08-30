
package producer_consumer;

import java.util.Scanner;
public class Producer_consumer {

    static int x;
    static int mutex=1;
    static int e= 5; 
    static int f=0;
   static   int wait(int s)
        {
            return --s ;
        }
       static int signal(int s)
        {
            return ++s ;
        }
       static  void producer()
        {
            mutex= wait(mutex);
            f=signal(f);
            e= wait(e);
            x++;
            System.out.println("producer has produce the item \n");
            mutex= signal(mutex);
        }
       static void consumer()
        {
             mutex= wait(mutex);
            f=wait(f);
            e= signal(e);
            x--;
            System.out.println("consumer has consume the item \n");
            mutex= signal(mutex);
        }   
    
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
       
        while(true)
                {
                 System.out.println(" 1.Producer 2.Consumer 3.Exit");
                 int ch = sc.nextInt();
                 switch (ch)
                 {
                     case 1:
                         if(mutex==1 && f!=5){
                         producer();
                        
                         }
                         else 
                         System.out.println(" producer is in Waiting state \n");    
                     break;
                     case 2:
                         if(mutex==1 && e!=1){
                             consumer();
                 
                         }
                         else 
                             System.out.println("Consumer is in waiing state \n");
                         break;
                     case 3:
                        System.exit(0);
                         break;   
                      }
                }
    }
       
}
