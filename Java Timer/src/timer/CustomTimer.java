/**
 * Written by 
 * @author Ck 
 * on 14May,2017
 * Email - karthik.n.sukumar@gmail.com
*/
package timer;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CustomTimer
{
	private int ms;
	/**
	 * @return the ms
	 */
	public int getMs()
	{
		return ms;
	}
	/**
	 * @param ms the ms to set
	 */
	public void setMs(int ms)
	{
		this.ms = ms;
	}
	/**
	 * @return the seconds
	 */
	public int getSeconds()
	{
		return seconds;
	}
	/**
	 * @param seconds the seconds to set
	 */
	public void setSeconds(int seconds)
	{
		this.seconds = seconds;
	}
	/**
	 * @return the taskPerformer
	 */
	public ActionListener getTaskPerformer()
	{
		return taskPerformer;
	}

	private int seconds;
	
	CustomTimer(int ms, int seconds)
	{
		this.ms = ms;
		this.seconds = seconds;
	}

	ActionListener taskPerformer = new ActionListener() {
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
	};
	private void printtime(int seconds2, int ms2)
	{
		System.out.printf("%02d:%02d\n",seconds2,ms2);
	}
}
