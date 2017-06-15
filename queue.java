import java.util.*;
class Queue<E>{
  private class Element<E>{
    private E data;
    privat Element<E> next;
    
    Element(E data){
        this.data = data;
        this.next = null;
    }
    
  }
  
  private Element<E> front;
  private Element<E> back;
  public Queue(){
      this.front = null;
      this.back = null;
  }
  public boolean isEmpty(){
      return front == null || back == null;
  }
  public void enqueue(E value){
  Element<E> newElement = new Element<E>(value);
  if(this.isEmpty()){
      this.front = newElement;
  }
  else{
      
      this.back.next = newElement;
  }
  this.back = newElement;
  }
  
  public E dequeue(){
          if(isEmpty()){
              throw new NoSuchElementException();
          }
          Element<E> head = front;
          this.front = front.next;
          return head.data;
  }
  public E peekFirst(){
       if(isEmpty()){
        throw new NoSuchElementException();
       }
       return this.front.data;
  }
  
  public E peekLast(){
      if(this.isEmpty()){
          throw new NoSuchElementException();
      }
      return this.back.data;
  }
  
}

}
