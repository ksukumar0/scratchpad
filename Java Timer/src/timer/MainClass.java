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
		int delay = 10; //1000 milliseconds = 1 second so this is 30 seconds
	//...Now create your action listener which is what is fired every 30 seconds
		ActionListener taskPerformer = new ActionListener() {
		private int ms=100;
		private int seconds=5;

		@Override
		public void actionPerformed(ActionEvent e)
		{
			if (seconds >= 0)
			{
				if ( ms <= 0 )
				{	
					ms = 100;
					seconds--;
				}
				ms--;
				if ( seconds >= 0)
					printtime(seconds,ms);
			}
		}

		private void printtime(int seconds2, int ms2)
		{
			System.out.printf("%02d:%02d\n",seconds2,ms2);
		}
	};
	new Timer(delay, taskPerformer).start(); //...Create the timer, add the delay which we set to 30 seconds as the first param, add the action listener it is to fire as the second param, them start it running. :)
	}
}
