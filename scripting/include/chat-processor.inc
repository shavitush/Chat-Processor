#if defined _chat_processor_included
  #endinput
#endif
#define _chat_processor_included

//Globals
#define MAXLENGTH_INPUT		128
#define MAXLENGTH_NAME		64
#define MAXLENGTH_MESSAGE	256

enum eChatFlags
{
	ChatFlag_Invalid,
	ChatFlag_All,
	ChatFlag_Team,
	ChatFlag_Spec,
	ChatFlag_Dead
}

//Forwards
/**
* Called while sending a chat message before It's sent.
* Limits on the name and message strings can be found above.
*
* param author			Author that created the message.
* param recipients		Array of clients who will receive the message.
* param flag			Determines which type of message is being sent.
* param name			Name string of the author to be pushed.
* param message			Message string from the author to be pushed.
*
* noreturn
**/
forward Action OnChatMessage(int& author, Handle recipients, eChatFlags& flag, char[] name, char[] message);

/**
* Called after the chat message is sent to the designated clients by the author.
*
* param author			Author that sent the message.
* param recipients		Array of clients who received the message.
* param flag			Determines which type of message was sent.
* param name			Name string of the author.
* param message			Message string from the author.
*
* noreturn
**/
forward void OnChatMessagePost(int author, Handle recipients, eChatFlags flag, const char[] name, const char[] message);

/**
Shared plugin information
**/
public SharedPlugin _pl_chat_processor = 
{
	name = "chat-processor",
	file = "chat-processor.smx",
#if defined REQUIRE_PLUGIN
	required = 1
#else
	required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public _pl_chat_processor_SetNTVOptional()
{
	MarkNativeAsOptional("");
}
#endif