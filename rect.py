import tkinter as tk


class myapps:
    def __init__(self,root:tk.Tk,titles:str,widths:int,heights:int,backgrounds:str,steps:int,colors:int):
        self.root=root
        self.root.title(titles)
        self.root.geometry(str(widths)+"x"+str(heights))
        self.root.configure(background=backgrounds)
        self.canvas=tk.Canvas(background=backgrounds,width=widths,height=heights)
        self.canvas.pack(padx=1,pady=1)
        c=self.canvas
        for a in range(0,widths,steps*2):
            for b in range(0,heights,steps):
                bb=(b//steps & 1)
                
                c.create_rectangle(a+(bb*steps),b,a+steps+(steps*bb),b+steps,fill=colors )
        
        





def starts(titles:str,widths:int,heights:int,backgrounds:str,steps:int,colors:int):
    root=tk.Tk()
    apps=myapps(root,titles,widths,heights,backgrounds,steps,colors)
    root.mainloop()

titles:str="fill grids"
widths:int=640
heights:int=480
backgrounds:str="black"
steps:int=20
colors:int="white"
starts(titles,widths,heights,backgrounds,steps,colors)