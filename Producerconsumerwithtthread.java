
package producerconsumerwithtthread;

import java.util.ArrayList;
import java.util.Scanner;
public class Producerconsumerwithtthread {

    public static void main(String[] args) {
        ArrayList<Integer> b=new ArrayList<Integer>();
      Thread ob1 =new Thread(new Producer(b));
      ob1.start();
    }
    
}
class Producer implements Runnable 
{
ArrayList<Integer> b= null;
final int maxsize=5;

private int i=0;
Producer(ArrayList<Integer> b)
{
this.b=b;
}
public void Produce(int i)  throws InterruptedException
{
synchronized(b)
{
while(b.size()==maxsize)
{
System.out.print("\n Producer is Waiting.");
b.wait();
}
}
synchronized(b)
{
b.add(i);
b.wait();
b.notify();
}
}
public void run()
{
try{
while(true)
{
i++;
Produce(i);
}
}
catch(InterruptedException e)
{
System.out.print("This is an exception.");
}
}
}

class Consumer implements Runnable 
{
ArrayList<Integer> b= null;

Consumer (ArrayList<Integer> b)
{
this.b=b;
}
public void Consume()  throws InterruptedException
{
synchronized(b)
{
while(b.isEmpty())
{
System.out.print("\n Consumer is Waiting.");
b.wait();
}
}
synchronized(b)
{
b.remove(0);
b.wait();
b.notify();
}
}
public void run()
{
try{
while(true)
{

Consume();
}
}
catch(InterruptedException e)
{
System.out.print("This is an exception.");
}
}
}

