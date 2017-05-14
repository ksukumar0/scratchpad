/**
 * Written by 
 * @author Ck 
 * on 14May,2017
 * Email - karthik.n.sukumar@gmail.com
*/
package timer;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Timer;

public class MainClass
{

	public static void main(String[] args)
	{
		int delay = 1000; //1000 milliseconds = 1 second so this is 30 seconds
	//...Now create your action listener which is what is fired every 30 seconds
		ActionListener taskPerformer = new ActionListener() {
		private int count=5;

		@Override
		public void actionPerformed(ActionEvent e)
		{
			if (count >0)
			{
				count--;
				System.out.printf("%d\n",count);
			}
		}
	};
	new Timer(delay, taskPerformer).start(); //...Create the timer, add the delay which we set to 30 seconds as the first param, add the action listener it is to fire as the second param, them start it running. :)
	}
}
