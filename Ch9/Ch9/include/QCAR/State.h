/*==============================================================================
Copyright (c) 2010-2011 QUALCOMM Austria Research Center GmbH .
All Rights Reserved.
Qualcomm Confidential and Proprietary
			
@file 
    State.h

@brief
    Header file for State class.

==============================================================================*/
#ifndef _QCAR_STATE_H_
#define _QCAR_STATE_H_

// Include files
#include <QCAR/System.h>
#include <QCAR/Frame.h>

namespace QCARDataFlow {
    struct StateData;
}


namespace QCAR
{

// Forward declarations
class Trackable;


/// AR State
/**
 *  A consistent view on the augmented reality state
 *  including a camera frame and all trackables.
 *  Similar to Frame, State is a light weight object that
 *  shares its data among multiple instances. Copies are
 *  therefore cheap and suggested over usage of references.
 *  Notice: Trackables queried by the state can not be
 *  compared by pointer to Trackables queried by the tracker
 *  (even though they might reference the same tracked object).
 *  Trackables queried by the state represent a temporary and
 *  consistent view on the Augmented Reality state and can
 *  therefore not be modified. objects must be queried from
 *  the Tracker in order to modify them.
 */
class QCAR_API State
{
public:
    /// Default constructor.
    State();

    /// Copy constructor.
    State(const State& other);

    /// Destructor
    ~State();

    /// Thread safe assignment operator
    State& operator=(const State& other);

    /// Returns the Frame object that is stored in the State
    Frame getFrame() const;

    /// Returns the number of Trackable objects currently known to the SDK
    int getNumTrackables() const;

    /// Provides access to a specific Trackable
    /**
     *  The returned object is only valid as long as the State
     *  object is valid. Do not keep a copy of the pointer!
     */
    const Trackable* getTrackable(int idx) const;

    /// Returns the number of Trackable objects currently being tracked
    int getNumActiveTrackables() const;

    /// Provides access to a specific Trackable object currently being tracked.
    /**
     *  The returned object is only valid as long as the State
     *  object is valid. Do not keep a copy of the pointer!
     */
    const Trackable* getActiveTrackable(int idx) const;

protected:
    QCARDataFlow::StateData* mData;
};

} // namespace QCAR

#endif //_QCAR_STATE_H_
