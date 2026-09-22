package org.rahul;

import java.util.TreeSet;
import java.util.Iterator;

public class Tree {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		TreeSet<String> Colors = new  TreeSet<String>();
		Colors.add("Red");
		Colors.add("Blue");
		Colors.add("Green");
		Colors.add("Yellow");
		
		System.out.println("Treeset :");
		Iterator<String> itr = Colors.iterator();
		
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
		
		// Add all elements of one Treeset to another 
		TreeSet<String> Colors2 = new TreeSet<String>();
		Colors2.add("White");
		Colors2.add("Black");
		
		Colors2.addAll(Colors);
		System.out.println("After adding element");
		itr = Colors2.iterator();
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
		
		// Create a reverse order view of the tree Set
		
		System.out.println("Reverse order");
		TreeSet<String> reverseColors = new TreeSet<String>(Colors.descendingSet());
		itr = reverseColors.iterator();
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
		 
		// First and last element 
		
		System.out.println("First and Last Element of Treeset");
		System.out.println("FirstElement : " + Colors.first());
		System.out.println("LastElement : " + Colors.last());
		
		// Get TreeSet element greater than or equal to given element
		
		TreeSet<Integer> numbers = new TreeSet<Integer>();
		numbers.add(10);
		numbers.add(20);
		numbers.add(30);
		numbers.add(40);
		numbers.add(50);
		
		int number = 12;
		
		System.out.println("Ceiling");
		
		System.out.println("TreeSet" + numbers);
		System.out.println("Element greater than or equal to "
				+ number + ": " + numbers.ceiling(number));
		

	}

}
