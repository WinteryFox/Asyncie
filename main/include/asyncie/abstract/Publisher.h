#pragma once

#include "Subscriber.h"

namespace Asyncie {
    /**
     * A {@link Publisher} is a provider of a potentially unbounded number of sequenced elements, publishing them according to
     * the demand received from its {@link Subscriber}(s).
     * <p>
     * A {@link Publisher} can serve multiple {@link Subscriber}s subscribed {@link Publisher#subscribe(Subscriber)} dynamically
     * at various points in time.
     *
     * @param <T> the type of element signaled
     */
    template<typename T>
    struct Publisher {
        /**
         * Request {@link Publisher} to start streaming data.
         * <p>
         * This is a "factory method" and can be called multiple times, each time starting a new {@link Subscription}.
         * <p>
         * Each {@link Subscription} will work for only a single {@link Subscriber}.
         * <p>
         * A {@link Subscriber} should only subscribe once to a single {@link Publisher}.
         * <p>
         * If the {@link Publisher} rejects the subscription attempt or otherwise fails it will
         * signal the error via {@link Subscriber#onError}.
         *
         * @param subscriber the {@link Subscriber} that will consume signals from this {@link Publisher}
         */
        virtual void subscribe(const Subscriber<T> &subscriber) = 0;
    };
}