/**
 * Written by 
 * @author Ck 
 * on 14May,2017
 * Email - karthik.n.sukumar@gmail.com
*/
package timer;

import javax.swing.Timer;

public class MainClass
{
	public static void main(String[] args) throws InterruptedException
	{
		CustomTimer c = new CustomTimer(100,5);
		new Timer(10, c.getTaskPerformer()).start();
		Thread.sleep(10000);
		c.setMs(30);
		c.setSeconds(1);
		new Timer(10, c.getTaskPerformer()).start();
	}
}
