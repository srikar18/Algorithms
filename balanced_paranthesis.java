public class balanced_paranthesis{
  static class stack{
    int top=-1;
    char []items = new char[100];

    void push(char x){
      items[++top]=x;
    }

    char pop(){
      return items[top--];
    }

    boolean isEmpty(){
      return (top==-1)?true:false;
    }
  }

  static boolean isMatchingPair(char a,char b){
    if((a==')'&& b=='(')||(a==']'&& b=='[')||(a=='}'&& b=='{'))
      return true;
    return false;
  }

  static boolean isBalanced(char[] exp){
    stack s=new stack();
    for(int i=0;i<exp.length;i++){
      if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        s.push(exp[i]);
      if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
        if(s.isEmpty())
          return false;
        if(!isMatchingPair(exp[i],s.pop()))
          return false;
      }
    }

    if(s.isEmpty())
      return true;
    return false;
  }
  public static void main(String[] args){
    char []exp={'{','(',')','}','[',']'};
    if(isBalanced(exp))
      System.out.println("Balanced");
    else
      System.out.println("Not Balanced");
  }
}