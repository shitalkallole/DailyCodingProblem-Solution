import java.util.*;
class DoublyLinkedList
{
	int data;
	DoublyLinkedList leftNode;
	DoublyLinkedList rightNode;

	DoublyLinkedList(int dataToStore)
	{
		data=dataToStore;
		leftNode=null;
		rightNode=null;
	}
}
class day52_Hard_Lru
{
	public static void main(String args[])
	{
		int size,choice,key,value;
		DoublyLinkedList head=null;
		DoublyLinkedList tail=null;

		boolean cont=true;
		Scanner sc=new Scanner(System.in);
		
		HashMap<Integer,Integer> pageData=new HashMap<Integer,Integer>();
		HashMap<Integer,DoublyLinkedList> whereExist=new HashMap<Integer,DoublyLinkedList>();

		System.out.print("Enter Cache Size : ");
		size=sc.nextInt();

		while(cont)
		{
			System.out.print("\n1.put(k,v) 2.get(k) 3.LRU Array 4.Exit \nWhich Function u want to call : ");
			choice=sc.nextInt();

			switch(choice)
			{
				case 1:
						System.out.print("\nEnter Key and Value:");
						key=sc.nextInt();
						value=sc.nextInt();
					

						if(pageData.containsKey(key))
						{
							//First update val in hashmap
							pageData.put(key,value);


							if(head!=tail && head.data!=key)//Check if only one element present
							{
								DoublyLinkedList tempObj=whereExist.get(key);
								
								(tempObj.leftNode).rightNode=tempObj.rightNode;
								if(tempObj.rightNode!=null)//if it is not last node
									(tempObj.rightNode).leftNode=tempObj.leftNode;
								else
									tail=tempObj.leftNode;
								
								
								head.leftNode=tempObj;
								tempObj.rightNode=head;
								tempObj.leftNode=null;

								head=tempObj;
							}
						}
						else
						{
							if(size!=0)//space to store data
							{
								pageData.put(key,value);
								DoublyLinkedList tempObj=new DoublyLinkedList(key);
								whereExist.put(key,tempObj);

								if(head==null && tail==null)
								{
									head=tempObj;
									tail=tempObj;
								}
								else
								{
									head.leftNode=tempObj;
									tempObj.rightNode=head;
									head=tempObj;
								}

								size=size-1;
							}
							else
							{
								//first delete entry from hashmap
								pageData.remove(tail.data);
								whereExist.remove(tail.data);

								tail=tail.leftNode;
								tail.rightNode=null;

								pageData.put(key,value);
								DoublyLinkedList tempObj=new DoublyLinkedList(key);
								whereExist.put(key,tempObj);

								head.leftNode=tempObj;
								tempObj.rightNode=head;
								head=tempObj;								
							}
						}
					

						break;
				case 2:
						System.out.print("\nEnter Key to get Data : ");
						key=sc.nextInt();
						if(pageData.containsKey(key))
						{
							System.out.println("Data : "+pageData.get(key)+"\n");

							if(head!=tail && head.data!=key)//Check if only one element present
							{
								DoublyLinkedList tempObj=whereExist.get(key);
								
								(tempObj.leftNode).rightNode=tempObj.rightNode;
								if(tempObj.rightNode!=null)//if it is not last node
									(tempObj.rightNode).leftNode=tempObj.leftNode;
								else
									tail=tempObj.leftNode;
								
								
								head.leftNode=tempObj;

								tempObj.rightNode=head;
								tempObj.leftNode=null;

								head=tempObj;

							}	
						}
						else
							System.out.println("Enter valid key");

						break;
				case 3:
						DoublyLinkedList temp;
						temp=head;
						while(temp!=null)
						{
							System.out.print(temp.data+" ");
							temp=temp.rightNode;
						}	
						System.out.print("\n");
						break;
				case 4:
						cont=false;	
						break;
			}
		}


	}
}