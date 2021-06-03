import java.util.*;

class Program {
  public int[] arrayOfProducts(int[] array) {
      int[] product = new int[array.length];
      
      int midValue = 1;
      for(int i = 0; i < array.length; i++) {
          product[i] = midValue;
          midValue *= array[i];
      }

      midValue = 1;
      for(int i = array.length-1; i >= 0; i--) {
          product[i] *= midValue;
          midValue *= array[i];
      }
      
      return product;
  }
}