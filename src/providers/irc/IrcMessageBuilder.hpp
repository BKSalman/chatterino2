#pragma once

#include "common/Aliases.hpp"
#include "common/Outcome.hpp"
#include "messages/SharedMessageBuilder.hpp"
#include "providers/twitch/TwitchBadge.hpp"

#include <IrcMessage>
#include <QString>
#include <QVariant>

namespace chatterino {

struct Emote;
using EmotePtr = std::shared_ptr<const Emote>;

class Channel;
class TwitchChannel;

class IrcMessageBuilder : public SharedMessageBuilder
{
public:
    IrcMessageBuilder() = delete;

    explicit IrcMessageBuilder(Channel *_channel,
                               const Communi::IrcPrivateMessage *_ircMessage,
                               const MessageParseArgs &_args);
    explicit IrcMessageBuilder(Channel *_channel,
                               const Communi::IrcMessage *_ircMessage,
                               const MessageParseArgs &_args, QString content,
                               bool isAction);

    /**
     * @brief used for global notice messages (i.e. notice messages without a channel as its target)
     **/
    explicit IrcMessageBuilder(const Communi::IrcNoticeMessage *_ircMessage,
                               const MessageParseArgs &_args);

    MessagePtr build() override;

private:
    void appendUsername();
};

}  // namespace chatterino
