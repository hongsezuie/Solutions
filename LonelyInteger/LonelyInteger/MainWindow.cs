using System;
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

	protected void OnButton1Clicked (object sender, EventArgs e)
	{
		string move = "0 0 1 2 1";

		int[] a = new int [5];
		int _a_item;

		String[] move_split = move.Split(' ');
		for(int _a_i = 0; _a_i < move_split.Length; _a_i++) {
			_a_item = Convert.ToInt32(move_split[_a_i]);
			a[_a_i] = _a_item;
		}

		Dictionary<int,int> HashMap = new Dictionary<int, int> ();

		foreach (var element in a) {
			if (HashMap.ContainsKey (element)) {
				HashMap [element]++;
			} else {
				HashMap.Add (element, 1);
			}
		}
		int result = 0;
		foreach (var elem in HashMap) {
			if (elem.Value == 1) {
				result = elem.Key;
				break;
			}
		}

		MessageDialog md = new MessageDialog (null, DialogFlags.Modal, MessageType.Info, ButtonsType.Ok, Convert.ToString(result));
		md.Run ();
		md.Destroy();
	}
}
