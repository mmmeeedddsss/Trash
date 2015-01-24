// Fig. 23.6: TicTacToeClient.cs
// Client for the TicTacToe program.
using System;
using System.Drawing;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Threading;  
using System.IO;         

public partial class TicTacToeClientForm : Form
{
   public TicTacToeClientForm()
   {
      InitializeComponent();
   } // end constructor

   private Square[ , ] board; // local representation of the game board 
   private Square currentSquare; // the Square that this player chose   
   private Thread outputThread; // Thread for receiving data from server
   private TcpClient connection; // client to establish connection      
   private NetworkStream stream; // network data stream                 
   private BinaryWriter writer; // facilitates writing to the stream    
   private BinaryReader reader; // facilitates reading from the stream  
   private char myMark; // player's mark on the board                   
   private bool myTurn; // is it this player's turn?                    
   private SolidBrush brush; // brush for drawing X's and O's           
   private bool done = false; // true when game is over                 

   // initialize variables and thread for connecting to server
   private void TicTacToeClientForm_Load( object sender, EventArgs e )
   {
      board = new Square[ 3, 3 ];

      // create 9 Square objects and place them on the board
      board[ 0, 0 ] = new Square( board0Panel, ' ', 0 );    
      board[ 0, 1 ] = new Square( board1Panel, ' ', 1 );    
      board[ 0, 2 ] = new Square( board2Panel, ' ', 2 );    
      board[ 1, 0 ] = new Square( board3Panel, ' ', 3 );    
      board[ 1, 1 ] = new Square( board4Panel, ' ', 4 );    
      board[ 1, 2 ] = new Square( board5Panel, ' ', 5 );    
      board[ 2, 0 ] = new Square( board6Panel, ' ', 6 );    
      board[ 2, 1 ] = new Square( board7Panel, ' ', 7 );    
      board[ 2, 2 ] = new Square( board8Panel, ' ', 8 );    

      // create a SolidBrush for writing on the Squares
      brush = new SolidBrush( Color.Black );           
  
      // make connection to server and get the associated
      // network stream                                  
      connection = new TcpClient( "127.0.0.1", 50000 );   
      stream = connection.GetStream();                   
      writer = new BinaryWriter( stream );               
      reader = new BinaryReader( stream );               

      // start a new thread for sending and receiving messages
      outputThread = new Thread( new ThreadStart( Run ) );    
      outputThread.Start();                                   
   } // end method TicTacToeClientForm_Load

   // repaint the Squares
   private void TicTacToeClientForm_Paint( object sender, 
      PaintEventArgs e )
   {
      PaintSquares();
   } // end method TicTacToeClientForm_Load

   // game is over
   private void TicTacToeClientForm_FormClosing( object sender, 
      FormClosingEventArgs e )
   {
      done = true;                                           
      System.Environment.Exit( System.Environment.ExitCode );
   } // end TicTacToeClientForm_FormClosing

   // delegate that allows method DisplayMessage to be called
   // in the thread that creates and maintains the GUI       
   private delegate void DisplayDelegate( string message );  

   // method DisplayMessage sets displayTextBox's Text property
   // in a thread-safe manner
   private void DisplayMessage( string message )
   {
      // if modifying displayTextBox is not thread safe
      if ( displayTextBox.InvokeRequired )
      {
         // use inherited method Invoke to execute DisplayMessage
         // via a delegate                                       
         Invoke( new DisplayDelegate( DisplayMessage ),          
            new object[] { message } );                          
      } // end if
      else // OK to modify displayTextBox in current thread
         displayTextBox.Text += message;
   } // end method DisplayMessage

   // delegate that allows method ChangeIdLabel to be called
   // in the thread that creates and maintains the GUI       
   private delegate void ChangeIdLabelDelegate( string message );  

   // method ChangeIdLabel sets displayTextBox's Text property
   // in a thread-safe manner
   private void ChangeIdLabel( string label )
   {
      // if modifying idLabel is not thread safe
      if ( idLabel.InvokeRequired )
      {
         // use inherited method Invoke to execute ChangeIdLabel
         // via a delegate                                       
         Invoke( new ChangeIdLabelDelegate( ChangeIdLabel ),          
            new object[] { label } );                          
      } // end if
      else // OK to modify idLabel in current thread
         idLabel.Text = label;
   } // end method ChangeIdLabel

   // draws the mark of each square
   public void PaintSquares()
   {
      Graphics g;

      // draw the appropriate mark on each panel
      for ( int row = 0; row < 3; row++ )
      {
         for ( int column = 0; column < 3; column++ )
         {
            // get the Graphics for each Panel                    
            g = board[ row, column ].SquarePanel.CreateGraphics();

            // draw the appropriate letter on the panel        
            g.DrawString( board[ row, column ].Mark.ToString(),
               board0Panel.Font, brush, 10, 8 );               
         } // end for
      } // end for
   } // end method PaintSquares

   // send location of the clicked square to server
   private void square_MouseUp( object sender, 
      System.Windows.Forms.MouseEventArgs e )
   {
      // for each square check if that square was clicked
      for ( int row = 0; row < 3; row++ )
      {
         for ( int column = 0; column < 3; column++ )
         {
            if ( board[ row, column ].SquarePanel == sender )
            {
               CurrentSquare = board[ row, column ];

               // send the move to the server                     
               SendClickedSquare( board[ row, column ].Location );
            } // end if
         } // end for
      } // end for
   } // end method square_MouseUp

   // control thread that allows continuous update of the
   // TextBox display
   public void Run()
   {
      // first get players's mark (X or O)                 
      myMark = reader.ReadChar();                          
      ChangeIdLabel( "You are player \"" + myMark + "\"" );
      myTurn = ( myMark == 'X' ? true : false );           

      // process incoming messages
      try
      {
         // receive messages sent to client       
         while ( !done )                          
            ProcessMessage( reader.ReadString() );
      } // end try
      catch ( IOException )
      {
         MessageBox.Show( "Server is down, game over", "Error",
            MessageBoxButtons.OK, MessageBoxIcon.Error );
      } // end catch
   } // end method Run

   // process messages sent to client
   public void ProcessMessage( string message )
   {
      // if the move the player sent to the server is valid
      // update the display, set that square's mark to be
      // the mark of the current player and repaint the board
      if ( message == "Valid move." )
      {
         DisplayMessage( "Valid move, please wait.\r\n" );
         currentSquare.Mark = myMark;
         PaintSquares();
      } // end if
      else if ( message == "Invalid move, try again." )
      {
         // if the move is invalid, display that and it is now
         // this player's turn again
         DisplayMessage( message + "\r\n" );
         myTurn = true;
      } // end else if
      else if ( message == "Opponent moved." )
      {
         // if opponent moved, find location of their move
         int location = reader.ReadInt32();               

         // set that square to have the opponents mark and
         // repaint the board                             
         board[ location / 3, location % 3 ].Mark =       
            ( myMark == 'X' ? 'O' : 'X' );                
         PaintSquares();                                  

         DisplayMessage( "Opponent moved.  Your turn.\r\n" );

         // it is now this player's turn
         myTurn = true;
      } // end else if
      else
         DisplayMessage( message + "\r\n" ); // display message
   } // end method ProcessMessage

   // sends the server the number of the clicked square
   public void SendClickedSquare( int location )
   {
      // if it is the current player's move right now
      if ( myTurn )
      {
         // send the location of the move to the server
         writer.Write( location );                     

         // it is now the other player's turn
         myTurn = false;
      } // end if
   } // end method SendClickedSquare

   // write-only property for the current square
   public Square CurrentSquare
   {
      set
      {
         currentSquare = value;
      } // end set
   } // end property CurrentSquare
} // end class TicTacToeClientForm

/**************************************************************************
 * (C) Copyright 1992-2006 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/