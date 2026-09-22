/*
 * package org.rahul; //package org.rahul; import java.util.ArrayList; import
 * java.util.Iterator; public class colors { public static void main(String
 * []args) { ArrayList<String> Colors = new ArrayList<String>();
 * Colors.add("Red"); Colors.add("blue"); Colors.add("Green");
 * Colors.add("Yellow");
 * 
 * //Insert element Colors.add(0,"Black"); Iterator<String> lists =
 * Colors.iterator();
 * 
 * while (lists.hasNext()) { System.out.println(lists.next()); }
 * 
 * //Retrive Element
 * 
 * String element = Colors.get(2); System.out.println("Element at index 2 :" +
 * element);
 * 
 * 
 * 
 * 
 * }
 * 
 * }
 */



package org.rahul;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Collections;
public class colors {
	public static void main(String[] args) {
		ArrayList<String> Colors = new ArrayList<String>();

		// Q1 - Add colors and print collection
		Colors.add("Red");
		Colors.add("blue");
		Colors.add("Green");
		Colors.add("Yellow");

		Iterator<String> lists = Colors.iterator();

		System.out.println("Q1 - Colors:");

		while (lists.hasNext()) {
			System.out.println(lists.next());
		}

		// Q2 - Insert element at first position
		Colors.add(0, "Orange");

		System.out.println("\nQ2 - After inserting Black:");

		lists = Colors.iterator();

		while (lists.hasNext()) {
			System.out.println(lists.next());
		}

		// Q3 - Retrieve element at index 2
		String element = Colors.get(2);

		System.out.println("\nQ3 - Element at index 2: " + element);

		// Q4 - Update element
		Colors.set(2, "Black");

		System.out.println("\nQ4 - After updating index 2:");

		lists = Colors.iterator();

		while (lists.hasNext()) {
			System.out.println(lists.next());
		}

		// Q5 - Remove third element
		Colors.remove(2);

		System.out.println("\nQ5 - After removing third element:");

		lists = Colors.iterator();

		while (lists.hasNext()) {
			System.out.println(lists.next());
		}

		// Q6 - Search an element
		String searchColor = "Green";
		boolean found = false;

		lists = Colors.iterator();

		while (lists.hasNext()) {

			String color = lists.next();

			if (color.equals(searchColor)) {
				found = true;
				break;
			}
		}

		System.out.println("\nQ6 - Search Result:");

		if (found) {
			System.out.println(searchColor + " is present in the ArrayList.");
		} else {
			System.out.println(searchColor + " is not present in the ArrayList.");
		}
		
		//Q7 Sort the arrayList
		Collections.sort(Colors);
		System.out.println("Q 7 - After Sorting");
		lists = Colors.iterator();
		while(lists.hasNext()) {
			System.out.println(lists.next());
		}
		//Q8  Copy the arraylist
		ArrayList<String>Colors2 = new ArrayList<String>();
		Colors2.add("");
		Colors2.add("");
		Colors2.add("");
		Colors2.add("");
		Collections.copy(Colors2, Colors);
		System.out.println("Q8 - Copied Arraylist");
		lists = Colors.iterator();
		while (lists.hasNext()) {
			System.out.println(lists.next());
		}
		//Q9 Shuffle the arraylist
		
		Collections.shuffle(Colors);
		System.out.println("After Shuffle");
		lists = Colors.iterator();
		while(lists.hasNext()) {
			System.out.println(lists.next());
		}
		//Q 10 Reverse the Arraylists 
		
		Collections.reverse(Colors);
		System.out.println("After reversing");
		lists=Colors.iterator();
		while (lists.hasNext()) {
			System.out.println(lists.next());
		}
		
		
		
		
		
	}
	

	
}

















