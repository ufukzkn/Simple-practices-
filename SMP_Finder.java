
public class SMP_Finder {
    public static void main(String[] args) {
        int[][] maze_1 = {{25,30,15,13,10},
                {3,90,80,76,14},
                {18,92,34,47,56},
                {42,59,5,8,77},
                {69,58,12,9,2}};
        int[][] maze_2 = {{528,507,402,535,31,206,45,136,346,66},
                {696,129,339,3,115,304,612,472,661,52},
                {318,311,255,87,199,108,269,122,164,38},
                {367,262,458,416,374,388,437,430,276,185},
                {556,465,10,381,640,682,514,332,192,59},
                {353,598,591,290,626,234,409,521,24,241},
                {444,479,486,570,171,542,325,668,360,549},
                {493,213,297,689,101,178,395,248,73,283},
                {654,423,143,605,675,577,563,17,619,94},
                {633,220,150,584,157,451,500,227,647,80},
        };
        int[][] maze_3 = {{238,173,123,193,23,208,33},
                {68,228,133,98,83,28,58},
                {73,223,38,163,93,103,18},
                {118,43,138,88,113,198,108},
                {143,78,158,168,233,13,148},
                {218,203,8,53,48,3,243},
                {213,178,188,183,153,128,63},
        };
        int[][] maze_4 = {{10,30,60},
                {40,25,12},
                {65,6,58},
                {78,36,90}};

        System.out.println("Maze 1 SMP:");
        finder(maze_1);
        System.out.println("\nMaze 2 SMP");
        finder(maze_2);
        System.out.println("\nMaze 3 SMP");
        finder(maze_3);
        System.out.println("\nMaze 4 SMP");
        finder(maze_4);

    }


    private static void finder(int[][] maze) {
        int from=1,to = 0,cost=maze[0][0];                      //1 for up
        int little;                                             //2 for right
        int i=0,j=0;                                            //3 for left
                                                                //4 for down
        System.out.print(maze[0][0]);
        while (j<maze.length-1)
        {
            little=100000;
            if (j!=maze.length-1)
                if ((maze[i][j+1]<little)&& from!=2)        //to right
                {little=maze[i][j+1];  to=2; }

            if (i!=maze.length-1)
                if ((maze[i+1][j]<little)&& from!=4)        //to down
                {little=maze[i+1][j];  to=4; }

            if (j!=0)
                if ((maze[i][j-1]<little)&& from!=3)        //to left
                    {little=maze[i][j-1]; to=3;  }

            if (i!=0)
                    if ((maze[i-1][j]<little)&& from!=1)    //to up
                    {little=maze[i-1][j];  to=1; }

            if (to==1) {i--; from=4;}
            if (to==2) {j++; from=3;}
            if (to==3) {j--; from=2;}
            if (to==4) {i++; from=1;}
            cost+=little;
            maze[i][j]=10000;
            if (little==10000)
                {
                    System.out.println("   Could not find SMP!!!");
                    break;
                }
            System.out.print("->"+little);
            if (j==maze.length-1) System.out.println("  cost="+cost);


        }
    }
}
