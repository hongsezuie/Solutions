using System;
using System.Linq;
using System.Collections.Generic;
using Gtk;

public partial class MainWindow: Gtk.Window
{
	public MainWindow () : base (Gtk.WindowType.Toplevel)
	{
		Build ();
	}

	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}

	static void QuickSort(List<int> arr, int InputStartingIndex, int InputPivotIndex){
		if (InputPivotIndex - InputStartingIndex > 0) {
			int FirstBig = -1;
			for (int i = InputStartingIndex; i < InputPivotIndex; i++) {
				if (arr [i] < arr [InputPivotIndex]) {
					if (FirstBig > -1) {
						int temp = arr [i];
						arr [i] = arr [FirstBig];
						arr [FirstBig] = temp;
						FirstBig++;
					}
				} else {
					if (FirstBig == -1) {
						FirstBig = i;
					}
				}
			}

			if (FirstBig > -1) {
				int temp_2 = arr [InputPivotIndex];
				arr [InputPivotIndex] = arr [FirstBig];
				arr [FirstBig] = temp_2;
			}


			Console.WriteLine (String.Join (" ", arr));

			if(FirstBig==-1){
				QuickSort(arr,0,InputPivotIndex-1);  
			} else if (FirstBig == InputStartingIndex) {
				QuickSort (arr, InputStartingIndex+1, InputPivotIndex);
			} else if (FirstBig > InputStartingIndex) {
				QuickSort (arr, InputStartingIndex, FirstBig - 1);
				QuickSort (arr, FirstBig + 1, InputPivotIndex);
			}
		}
	}

	protected void OnButton1Clicked (object sender, EventArgs e)
	{
		int n=Convert.ToInt32("5");
		List<int> _arr = Convert.ToString ("5 4 2 1 3").Split (' ').ToList ().Select (x => int.Parse (x)).ToList ();

		int PivotIndex=n-1;
		try
		{
			QuickSort(_arr, 0, PivotIndex);
		}
		catch(Exception) {
			throw new Exception ("!");
		}
	}
}
