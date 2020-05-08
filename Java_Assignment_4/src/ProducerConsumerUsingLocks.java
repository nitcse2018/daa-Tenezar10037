import java.util.concurrent.*;
import java.util.concurrent.locks.*;

import java.util.LinkedList;

public class ProducerConsumerUsingLocks {

	private static Buffer buffer = new Buffer();
	
	public static void main(String[] args) {
		// Thread pool with two threads
		ExecutorService exec = Executors.newFixedThreadPool(2);
		exec.execute(new ProducerTask());
		exec.execute(new ConsumerTask());
		exec.shutdown();
	}
	
	// Adding to the Buffer
	private static class ProducerTask implements Runnable {
		public void run() {
			try {
				int i = 1;
				while(true) {
					System.out.println("\t\t\tProducer writes " + i);
					buffer.write(i++);
					Thread.sleep((int)(Math.random()*10000));
				}
			}
			
			catch (Exception e){
				e.printStackTrace();
			}
		}
	}
	
	private static class ConsumerTask implements Runnable {
		public void run() {
			try {
				while(true) {
					System.out.println("\t\t\tConsumer reads " + buffer.read());
					Thread.sleep((int)(Math.random()*10000));
				}
			}
			
			catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	private static class Buffer {
		private static final int CAPACITY = 1; // Buffer Size
		private LinkedList<Integer> queue = new LinkedList<>();
		
		//Creating Lock
		private static Lock lock = new ReentrantLock();
		
		//Creating conditions
		private static Condition notEmpty = lock.newCondition();
		private static Condition notFull = lock.newCondition();
		
		public void write(int value) {
			lock.lock(); // Acquire the lock
			try {
				while(queue.size() == CAPACITY) {
					System.out.println("\t\t\tWait for notFull condition");
					notFull.await();
				}
				queue.offer(value);
				notEmpty.signal(); //Signal notEmpty condition
			}
			catch(Exception e) {
				e.printStackTrace();
			}
			finally {
				lock.unlock();
			}
		}
		
		public int read() {
			int value = 0;
			lock.lock();
			try {
				while(queue.isEmpty()) {
					System.out.println("\t\t\tWait for notEmpty condition");
					notEmpty.await();
				}
				value = queue.remove();
				notFull.signal(); // Signal notFull condition
			}
			catch (Exception e) {
				e.printStackTrace();
			}
			finally {
				lock.unlock(); // Release the lock
				return value;
			}
		}
	}

}
