#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

size_t split( const std::string &txt,std::vector< std::string > &strs,char ch );

int main()
{
    std::string Q_str,S_str,q0,F_str;
    std::vector< std::string > Q_vec,S_vec,F_vec;
    std::map< std::string,std::string > delta;
    
    //input gathering
    
    std::cout << "Q (states): ";
    std::getline( std::cin,Q_str );
    
    std::cout << "S (alphabet): ";
    std::getline( std::cin,S_str );
    
    std::cout << "q0 (first state): ";
    std::getline( std::cin,q0 );
    
    std::cout << "qF (accept states): ";
    std::getline( std::cin,F_str );
    
    
    split( Q_str,Q_vec,' ' );
    split( S_str,S_vec,' ' );
    split( F_str,F_vec,' ' );
    
    std::cout << "delta (transitions):" << std::endl;
    
    for( int i = 0; i < Q_vec.size(); i++ )
    {
        for( int j = 0; j < S_vec.size(); j++ )
        {
            std::string prompt = Q_vec.at( i ) + S_vec.at( j );
            std::cout << prompt ;
            std::string in;
            std::getline( std::cin,in );
            delta.insert( std::pair< std::string,std::string >( prompt,in ) );
            
        }
    }
    
    std::string in;
    
    std::cout << "string: ";
    std::getline( std::cin,in );
    
    while( in != "" )
    {
        std::string state = q0;
        
        for( int i = 0; i < in.size(); i++ ) //go through the string, follow the prompt and update current state
        {
            std::string prompt = state + in.at( i ); // for example Aa, delta map tells us the next state
            state = delta.at( prompt ); //update current state to next state
        }
        
        if ( std::find( F_vec.begin(),F_vec.end(),state ) != F_vec.end() ) std::cout << "accepted\n" << std::endl; //if last state in F_vec
        else std::cout << "rejected\n" << std::endl;
        
        std::cout << "string: ";
        std::getline( std::cin,in );
    }
        
    return 0;
}


size_t split( const std::string &txt,std::vector< std::string > &strs,char ch ) //split string to string vec based on char delimiter
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos )
    {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;
       

        pos = txt.find( ch,initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos,std::min( pos,txt.size() ) - initialPos + 1 ) );

    return strs.size();
}
