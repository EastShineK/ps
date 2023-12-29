import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class ProduceConumerPro {
	static BlockingQueue<Integer> queue = new ArrayBlockingQueue<Integer> (5);
	
	public static void main(String[] args) { 
		Consumer consumer = new Consumer(queue);
		consumer.start();
		Producer producer = new Producer(queue);
		producer.start();
		
		//System.out.println("end");
	}
}

class Producer extends Thread{
	
	BlockingQueue<Integer> queue;
	
	Producer(BlockingQueue<Integer> queue) {  
        this.queue = queue;  
    }
	
	public void run() {
		int data = 0;
		while(true) {
			try {
				Thread.sleep(300);
				/*for(int i = 0; i < 10; i++) {
					int data = i;
					queue.put(data);
					System.out.println("Produced: " + data);
				}*/
				//int data = 0;
				if(data < 10) {
					queue.put(data);
					System.out.println("Produced: " + data);
					data++;
				}
				if(data > 9) {
					break;
				}
				
			} catch(InterruptedException e) {
				
			}
		}
	}
}

class Consumer extends Thread{
	
	BlockingQueue<Integer> queue;
	
	Consumer(BlockingQueue<Integer> queue) {
        this.queue = queue;  
    } 
	
	public void run() {
		while(true) {
            try {
            	Thread.sleep(1000);
                Integer index = queue.take();  
                System.out.println("Consumed : " + index);
                if(queue.isEmpty()) {
                	break;
                }
            } catch (InterruptedException e) {  
                e.printStackTrace();  
            }  
        }
	}
}
