/*using functions makes program to read
 easily*/
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
typedef short s;
s a[15][15]={{0}};
s b[8][5]={{0}};
s d=1,x=0;
s g[4];
//void sort();
s eyyi()
{
			s t;
			srand((unsigned)time(NULL))	;
			t= ( rand()%5)+1;
			if(t==1)
				    cout<<"⚀";
			else if(t==2)
				    cout<<"	⚁";
			else if(t==3)
				    cout<<"⚂";
			else if(t==4)
				    cout<<"⚃";
			else if(t==5) 
				    cout<<"⚄";
			else
				   cout<<"⚅";
				
cout<<"\n";
return t;
}
void enchu (s o,s &k,s &l);
s edi(s c);
//void jarupu(s t,s k, s l,s m,s n );
void champu(s v);
bool safe(s k, s l)
{return ((l==1||l==12)&&k==6)||((l==2||l==13)&&k==8)||(l==6&&(k==2||k==13))||(l==8&&(k==1||k==12));}
bool home1(s k, s l)
{
				return ((k==11&&(l==1||l==3))||(k==13&&(l==1||l==3)));
}
bool home2(s k, s l)
{
return ((k==1&&(l==1||l==3))||(k==3&&(l==1||l==3)));
}
bool home3(s k, s l)
{
				return ((k==1&&(l==11||l==13))||(k==3&&(l==11||l==13)));
}
bool home4(s k,s l)
{
				return ((k==11&&(l==11||l==13))||(k==13&&(l==11||l==13)));
}
bool home(s k, s l)
{
				return (home1(k,l)||home2(k,l)||home3(k,l)||home4(k,l));
}
				
void  pl(s k,s l);
void next(s t,s &k,s &l){
//s m=k,n=l;s p;
//s u=a[k][l],v=a[m][n];/*v-new ;u - old*/
//s v=a[k][l];
if(d==6&&//home(m,n)
			home(k,l)	){
    if(t/4==1){	 
    k=13;	l=6;
  		}
  	 else if(t/4==2){
  		k=6;l=1;
  		}
	  else if(t/4==3){
   	 k=1;l=8;
	   	}
    	else if(t/4==4){
	  	k=8;l=13;
    }
						//return ;
}
else	if((k==6||k==7||k==8)&&
	         			(l==6||l==7||l==8)){
return;
}				
else{
    if(k==6)	{
		     if(l==5){
					k--;l++;
					}
					else if(l==14){
					k++;
					}
					else{
					l++;
					}
    }
    else if(k==8){
         if(l==0){
	     		k--;
	     		}
	     	 else if(l==9){
	     		k++;l--;
     			}
     	   else {
     			l--;
	     		}
    }
    else if(l==6){
        if(k==0){
     		 l++;
     		 }
     		else if(k==9){
     		k--;l--;
        }
     		else {
        k--;
					}
    }
    else if(l==8){
        if(k==5){
     		 k++;l++;
     			}
		     	else if(k==14){
      			l--;
	      		}
     			else {
     			k++;
	     		}
     }
    else	if(k==7){
	        if(l==0){
					       	if(t/4==2)
										l++;
										else
										k--;
					  }
				  	else if(l==14){
					        	if(t/4==4)
										  l--;
											else 
											k++;
						}
					 else if(l>0&&l<6){
						l++;
						}
					 else if(l>8&&l<15){
						l--;
						}
	  }
		else if(l==7){
		    if(k==0) {
				     if(t/4==3)
							k++;
							else 
							l++;
		   }
	    else if(k==14)	{
				    if(t/4==1)
						 k--;
						 else
					  	l--;
			 }
			 else if(k>0&&k<6)	{
				k++;
				}
				else if(k>8&&k<15){
				k--;
				}
  }
}
}
//no need to debug till this in
//function02/07/18							
void jarupu(s t,s k, s l,s m,s n)	{
short int  p,u=a[m][n];
if(a[k][l]==2)
//a[k][l]=a[m][n];
a[k][l]=t;
else if(safe(k,l)||a[k][l]/4==t/4||a[k][l]>19)	{	
//cout<<"need to encode\n ";
     if(a[k][l]<20){
			b[x][0]=a[k][l];b[x][1]=t;
			a[k][l]=20+x;x++;
			}
			else {   
							for(p=0;p<5;p++)	{
								  	if(b[a[k][l]-20][p]==0){
										b[a[k][l]-20][p]=t;				//	a[k][l]=a[k][l];
										break;
										}											//		else														
					  	}
				}
}
else {
champu(a[k][l]);
a[k][l]=t;				
}
u-=20;cout<<"thiyyu";
short int w=0, h=0;//s w;
if(a[m][n]<20)	{//			cout<<"it";
a[m][n]=2;
}
else {
				for(p=0;p<5;p++){
		 			    	if(b[u][p]==t){
											if(b[u][2]==0){//2 mrks  overlapped
									  				 if(p==0){
										     	  a[m][n]=b[u][1];
														b[u][1]=0;
													 	}
														else {
														a[m][n]=b[u][0];
														b[u][0]=0;
														}
										b[u][p]=0;
										cout<<"code to slide";				
										x--;					//			if(u!=0){
													 	for(w=u;w<8;w++){
														h=0;
															    if(b[w+1][0]==0)
                                  break;
												      		for(h=0;h<5;h++){
																	     if(b[w+1][h]==0)
																      break;
	                               b[w][h]=b[w+1][h];
														     }
																if(h!=0){
																short int t1,t2;
																enchu(w+20,t1,t2)	 ;		
																a[t1][t2]-=1;	//x=w-1;		
																}
												 }	//	if(u!=w)					//	x=w-1;
							      }			
						       	else{
				       			b[u][p]=0;	     //		sort();
											      for(w=p;w<4;w++){
																	  if(b[u][w+1]==0)
																		break;
																		b[u][w]=b[u][w+1];
																		b[u][w+1]=0;								//	p++;	
															}
					       		}
							}//if
					 }															
				}//elsej*
}
void print(s k)
{ 
s i,j;
for(i=0;i<15;i++)	{
     for(j=0;j<15;j++){
				    char c='a';
						 if(a[i][j]==2){
						     cout<<"🔳";																	
						 }
						else if(a[i][j]==0||a[i][j]==1){
						    cout<<"🔲";
						}
				  else if(a[i][j]>3&&a[i][j]<20){
					  /*   c=c+((a[i][j]/4)-1);
								cout<<c<<a[i][j]%4;	*/
			        		if(a[i][j]/4==1)		
									cout<<"⚪";
								  else 	if(a[i][j]/4==2)			
									cout<<"⚫";
									else if(a[i][j]/4==3)
									cout<<"🔴";
									else if(a[i][j]/4==4)
									cout<<"🔵";
				  	}
					 else if(a[i][j]==3){
					     cout<<"✡";
						}
						else if(a[i][j]>19){
						    cout<<a[i][j]%100;
					  }
			}
			cout<<endl;
}
				for(i=0;i<8;i++){
					   if(b[i][0]==0)
							break;
		  	cout<<endl<<i+20;
				      for(j=0;j<5;j++){
							       	if(b[i][j]==0)
						       		break;
								      else{
												char c='a';
												c+=((b[i][j]/4)-1);
								      cout<<c<<b[i][j]%4<<",";
												}
								}
				}
}
int main()
{
				s i=0,j=0,k=13,l,m,n,o,N=4;
				//N no. of players
				d=6;
				pl(i,j);
	  //		while(k!=10)
				{
							//	cin>>k;
				for(m=0;1;m++){
						//	cin>>k;
					//		d=eyyi();
				print(m%N);
				cout<<" player "<<m%N+1<<" please "
									<<" enter 1 to throw the die ";
				cin>>d;				     
		//	 	d=eyyi();
				srand((unsigned)time(NULL));
									if(rand()%4==0){
									d=6;
									cout<<"\n ⚅ ";
									 }
									else
									d=eyyi();
			 	k=edi(m%N+1);
			//			 d=eyyi();
						  		if(k>3&&k<20){
                 enchu(k,i,j);
									o=i;n=j;
						               for(l=0;l<d;l++)	{
													        		if(d==6&&home(i,j)){
													        		next(k,i,j);
											 	        			break;
											        				}
												        			else{
											         				next(k,i,j);
                                      }		
														}
							    	jarupu(k,i,j,o,n);									 
						    // 		print();
						    if(d==6)
						     m--;
										}
							}
					}
			cout<<"\nGame over!!";
		return 0;		
}
void  pl(s k,s l)
{
					//			s k,l;k=1;l=9;
		for(k=0;k<15;k++)		
				for(l=0;l<15;l++)
  {
								if((l>5&&l<9)||(k>5&&k<9))
			{
												a[k][l]=2;
				}
							if(k>5&&k<9&&l>5&&l<9)
								a[k][l]=1;
							else if(k==1)	
								{
							     	  if(l==1)
												{a[k][l]=8;}
												else if(l==3)
												{a[k][l]=9;}
												else if(l==11)
												{a[k][l]=12;}
												else if(l==13)
												{a[k][l]=13;}
												else if(l==9)
								      {a[k][l]=3;}
       				}			
								else if(k==3)	
					{
								if(l==1)
												{a[k][l]=10;}
								else if(l==3)
												{a[k][l]=11;}
								else if(l==11)
		  							{a[k][l]=14;}
								else if(l==13)
								      {a[k][l]=15;}
					}
								else if(k==11)
			  	{
								if(l==1)
												{a[k][l]=4;}
												else if(l==3)
												{a[k][l]=5;}
												else if(l==11)
												{a[k][l]=16;}
												else if(l==13)
												{a[k][l]=17;}
		   		}
								else if(k==13)
				{
								if(l==1)
												{a[k][l]=6;	}
												else if(l==3)
												{a[k][l]=7;}
												else if(l==11)
												{a[k][l]=18;}
												else if(l==13)
												{a[k][l]=19;}
												else if(l==5)
												a[k][l]=3;
												}
												else if(
								      ((k==2||k==13)&&l==5)||
								        (k==9&&(l==2||l==13))	||
							        	(k==5&&(l==1||l==12))||
							         ((k==1||k==12)&&l==9)
								      )
												{a[k][l]=3;		
											  }
				
   }
				}
void champu(s v)
{
		s		D=v/4,r=v%4;
if(D==1)
				{
				if(r==0)
								{a[11][1]=4;}
								else if(r==1)
								{a[11][3]=5;}
								else if(r==2)
								{a[13][1]=6;}
								else if(r==3)
								{a[13][3]=7;}
      }
else if(D==2)
				{
				if(r==0)
								{a[1][1]=8;}
								else if(r==1)
								{a[1][3]=9;}
								else if(r==2)
								{a[3][3]=10;}
       }
else if(D==3)
				{
								if(r==0)
								{a[1][11]=12;}
								else if(r==1)
								{a[1][13]=13;}
								else if(r==2)
            {a[3][11]=14;}
								else if(r==3)
								{a[3][13]=15;}
				}
else if(D==4)
				{
				if(r==0)
								{a[11][11]=16;}
								else if(r==1)
								{a[11][13]=17;}
								else if(r==2)
								{a[13][11]=18;}
								else if(r==3)
								{a[13][13]=19;}
      }
}

void enchu (s o,s &k, s &l){
      s i,j;
				for (i=0;i<15;i++)
				     for(j=0;j<15;j++){
				           if(o==a[i][j]){
												    k=i;l=j;return;
											}
							     	else if(a[i][j]>19){
											short int p,q;
										  //     	for(p=0;p<=x;p++)
												         for(q=0;q<5;q++)
												{
											//	if(o==b[p][q])
																if(o==b[a[i][j]-20][q])
														{k=i;l=j;//a[i][j]=o;
																//	goto here;		
																				return ;	}		
					       			}
											//	here:
								}
				 }			
				return ;	
}
s edi(s c)
{
		 s i,e,f,h=0;
				for(f=0;f<4;f++)
			 g[f]=0;
		  for(f=0;f<4;f++){
     enchu(c*4+f,i,e);
		        	if(!home(i,e)||d==6){
							 g[h]=c*4+f;
								h++;
            }
	   	}
			if(h!=0){
			cout<<"\nenter from";
	      		for(f=0;f<h;f++)
         cout<<g[f]%4+1<<",";
			e=0;
	       	do{
	     		cin>>i;
		            	for(f=0;f<h;f++){
			                if(g[f]%4+1==i)
							          return g[f];
                }
		      	}	while(e==0)	;
			}
				return 0;
}
/*void sort(){
s p,q,r,s,t,u;
  for(p=0;p<8;p++) {
    for ( q=1; q < 4; q ++) {
		       	if(b[p][q+1]==0){
							for(r=q+1;r<5;r++){
					        		if(b[p][r]!=0){
											q++;
											 b[p][q]=b[p][r];
											b[p][r]=0;
												}
						//	break;
							}			
    					}
			}			
  }
			
	
}*/
