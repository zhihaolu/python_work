package com.learningjava.shiyan_5;

public class laozhang {
    private String name;
    public Person(){
    }
    public Person(String name){
        this.name=name;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public abstract void doSomthing(Action action, Destination dest);
}
